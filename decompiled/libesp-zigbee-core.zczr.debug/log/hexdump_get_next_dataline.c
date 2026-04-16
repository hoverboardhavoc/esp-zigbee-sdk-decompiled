/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> hexdump_get_next_dataline
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

int hexdump_get_next_dataline
              (char *line,uint16_t width,uint8_t *data,uint16_t data_len,uint16_t idx)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002036;
  byte bVar4;
  undefined2 in_register_0000203a;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = CONCAT22(in_register_0000203a,idx);
  uVar7 = uVar2 + 0x10 & 0xffff;
  *line = '|';
  uVar6 = 1;
  for (uVar1 = uVar2; uVar1 < uVar7; uVar1 = uVar1 + 1 & 0xffff) {
    if (uVar1 < CONCAT22(in_register_00002036,data_len)) {
      iVar3 = snprintf(line + uVar6,CONCAT22(in_register_0000202e,width) - uVar6," %02X");
    }
    else {
      iVar3 = snprintf(line + uVar6,CONCAT22(in_register_0000202e,width) - uVar6,"   ");
    }
    uVar6 = iVar3 + uVar6 & 0xffff;
    if ((uVar1 & 7) == 7) {
      uVar5 = uVar6 + 1;
      line[uVar6] = ' ';
      uVar6 = uVar6 + 2 & 0xffff;
      line[uVar5 & 0xffff] = '|';
    }
  }
  line[uVar6] = ' ';
  for (; uVar6 = uVar6 + 1 & 0xffff, uVar2 < uVar7; uVar2 = uVar2 + 1 & 0xffff) {
    if (uVar2 < CONCAT22(in_register_00002036,data_len)) {
      bVar4 = data[uVar2];
      if (bVar4 < 0x7f) {
        if (((&_ctype_)[bVar4] & 0x97) == 0) {
          bVar4 = 0x2e;
        }
      }
      else {
        bVar4 = 0x2e;
      }
    }
    else {
      bVar4 = 0x20;
    }
    line[uVar6] = bVar4;
  }
  line[uVar6] = ' ';
  line[uVar6 + 1 & 0xffff] = '|';
  line[uVar6 + 2 & 0xffff] = '\0';
  return uVar7;
}

