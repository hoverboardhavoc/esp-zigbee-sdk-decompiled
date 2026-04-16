/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> hexdump_get_startline
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void hexdump_get_startline(char *line,uint16_t width,char *title,uint16_t data_len)

{
  size_t sVar1;
  int iVar2;
  undefined2 in_register_0000202e;
  int iVar3;
  int iVar4;
  
  iVar3 = CONCAT22(in_register_0000202e,width);
  sVar1 = strlen(title);
  sVar1 = sVar1 & 0xffff;
  iVar4 = (iVar3 - sVar1) + -10;
  if (iVar4 < 6) {
    sVar1 = (iVar4 + sVar1 & 0xffff) - 6 & 0xffff;
    iVar4 = 6;
  }
  iVar4 = iVar4 / 2;
  write_nchar(line,'=',(uint16_t)iVar4);
  line[iVar4] = '[';
  memcpy(line + iVar4 + 1,title,sVar1);
  iVar4 = sVar1 + iVar4 + 1;
  iVar2 = snprintf(line + iVar4,iVar3 - iVar4," len=%03u]");
  write_nchar(line + iVar2 + iVar4,'=',width - (short)(iVar2 + iVar4));
  line[iVar3] = '\0';
  return;
}

