// /*
//  *   This file is part of PKSM
//  *   Copyright (C) 2016-2019 Bernardo Giordano, Admiral Fish, piepie62
//  *
//  *   This program is free software: you can redistribute it and/or modify
//  *   it under the terms of the GNU General Public License as published by
//  *   the Free Software Foundation, either version 3 of the License, or
//  *   (at your option) any later version.
//  *
//  *   This program is distributed in the hope that it will be useful,
//  *   but WITHOUT ANY WARRANTY; without even the implied warranty of
//  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  *   GNU General Public License for more details.
//  *
//  *   You should have received a copy of the GNU General Public License
//  *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//  *
//  *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
//  *       * Requiring preservation of specified reasonable legal notices or
//  *         author attributions in that material or in the Appropriate Legal
//  *         Notices displayed by works containing it.
//  *       * Prohibiting misrepresentation of the origin of that material,
//  *         or requiring that modified versions of such material be marked in
//  *         reasonable ways as different from the original version.
//  */

// #include "mysterygift.hpp"

// static nlohmann::json mysteryGiftSheet;
// static u8* mysteryGiftData;

// void MysteryGift::init(Generation g)
// {
//     std::string path = StringUtils::format("romfs:/mg/sheet%s.json.bz2", genToCstring(g));
//     FILE* f          = fopen(path.c_str(), "rb");
//     if (f != NULL)
//     {
//         fseek(f, 0, SEEK_END);
//         size_t size          = ftell(f);
//         unsigned int destLen = 700 * 1024; // big enough
//         char* s              = new char[size];
//         char* d              = new char[destLen]();
//         rewind(f);
//         fread(s, 1, size, f);

//         int r = BZ2_bzBuffToBuffDecompress(d, &destLen, s, size, 0, 0);
//         if (r == BZ_OK)
//         {
//             mysteryGiftSheet = nlohmann::json::parse(d);
//         }

//         delete[] s;
//         delete[] d;
//     }

//     if (mysteryGiftSheet.is_discarded())
//     {
//         mysteryGiftSheet            = nlohmann::json::object();
//         mysteryGiftSheet["gen"]     = "BAD";
//         mysteryGiftSheet["matches"] = nlohmann::json::array();
//     }

//     path = StringUtils::format("romfs:/mg/data%s.bin.bz2", genToCstring(g));
//     f    = fopen(path.c_str(), "rb");
//     if (f != NULL)
//     {
//         fseek(f, 0, SEEK_END);
//         u32 size             = ftell(f);
//         unsigned int destLen = 800 * 1024;
//         char* s              = new char[size];
//         mysteryGiftData      = new u8[destLen]();
//         rewind(f);
//         fread(s, 1, size, f);

//         int r = BZ2_bzBuffToBuffDecompress((char*)mysteryGiftData, &destLen, s, size, 0, 0);
//         if (r != BZ_OK)
//         {
//             // TODO
//         }

//         delete[] s;
//     }
// }

// std::unique_ptr<WCX> MysteryGift::wondercard(size_t index)
// {
//     std::string gen = mysteryGiftSheet["gen"];

//     auto entry = mysteryGiftSheet["wondercards"][index];

//     u32 offset = entry["offset"];

//     if (gen == "4")
//     {
//         std::unique_ptr<WCX> wc = nullptr;
//         if (entry["type"] == "wc4")
//         {
//             wc = std::make_unique<WC4>(mysteryGiftData + offset);
//         }
//         else
//         {
//             wc = std::make_unique<PGT>(mysteryGiftData + offset);
//         }
//         return wc;
//     }
//     else if (gen == "5")
//     {
//         PGF* pgf = new PGF(mysteryGiftData + offset);
//         return std::unique_ptr<WCX>(pgf);
//     }
//     else if (gen == "6")
//     {
//         WC6* wc6 = new WC6(mysteryGiftData + offset, entry["type"].get<std::string>().find("full") != std::string::npos);
//         return std::unique_ptr<WCX>(wc6);
//     }
//     else if (gen == "7")
//     {
//         WC7* wc7 = new WC7(mysteryGiftData + offset, entry["type"].get<std::string>().find("full") != std::string::npos);
//         return std::unique_ptr<WCX>(wc7);
//     }
//     else if (gen == "LGPE")
//     {
//         WB7* wb7 = new WB7(mysteryGiftData + offset, entry["type"].get<std::string>().find("full") != std::string::npos);
//         return std::unique_ptr<WCX>(wb7);
//     }
//     else
//     {
//         return nullptr;
//     }
// }

// void MysteryGift::exit(void)
// {
//     delete[] mysteryGiftData;
//     mysteryGiftSheet.clear();
// }

// std::vector<nlohmann::json> MysteryGift::wondercards()
// {
//     return mysteryGiftSheet["matches"];
// }

// MysteryGift::giftData MysteryGift::wondercardInfo(size_t index)
// {
//     giftData ret;
//     nlohmann::json entry = mysteryGiftSheet["wondercards"][index];
//     ret.name             = entry["name"].get<std::string>();
//     ret.game             = entry["game"].get<std::string>();
//     ret.form             = entry["form"];
//     ret.species          = entry["species"];
//     return ret;
// }
