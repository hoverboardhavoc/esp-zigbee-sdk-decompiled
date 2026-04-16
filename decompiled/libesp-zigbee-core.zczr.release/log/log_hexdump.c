/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> log.o -> log_hexdump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void log_hexdump(log_level_t level,char *tag,char *title,void *buf,uint32_t size)

{
  size_t sVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  byte local_8c [4];
  char line [73];
  
  sVar1 = strlen(title);
  sVar1 = sVar1 & 0xffff;
  iVar6 = 0x3e - sVar1;
  if (iVar6 < 6) {
    sVar1 = (sVar1 - 6) + iVar6 & 0xffff;
    iVar6 = 6;
  }
  uVar7 = iVar6 >> 1;
  uVar4 = uVar7 & 0xffff;
  pbVar10 = local_8c;
  while (uVar4 = uVar4 - 1 & 0xffff, uVar4 != 0xffff) {
    *pbVar10 = 0x3d;
    pbVar10 = pbVar10 + 1;
  }
  local_8c[uVar7] = 0x5b;
  memcpy(local_8c + uVar7 + 1,title,sVar1);
  iVar9 = sVar1 + uVar7 + 1;
  iVar6 = snprintf((char *)(local_8c + iVar9),0x48 - iVar9," len=%03u]");
  for (pbVar10 = local_8c + iVar9 + iVar6;
      ((uint)pbVar10 & 0xffff) != ((uint)(line + 0x44) & 0xffff); pbVar10 = pbVar10 + 1) {
    *pbVar10 = 0x3d;
  }
  line[0x44] = '\0';
  log_write(level,tag,"%s");
  for (uVar4 = 0; uVar4 < size; uVar4 = uVar4 + 0x10 & 0xffff) {
    local_8c[0] = 0x7c;
    iVar6 = 0x11;
    if (0xffef < uVar4) {
      iVar6 = 1;
    }
    uVar8 = 1;
    for (uVar7 = uVar4; pbVar10 = local_8c + uVar8, uVar7 != ((uVar4 - 1) + iVar6 & 0xffff);
        uVar7 = uVar7 + 1 & 0xffff) {
      if (uVar7 < (size & 0xffff)) {
        iVar9 = snprintf((char *)pbVar10,0x48 - uVar8," %02X");
      }
      else {
        iVar9 = snprintf((char *)pbVar10,0x48 - uVar8,"   ");
      }
      uVar8 = iVar9 + uVar8 & 0xffff;
      if ((uVar7 & 7) == 7) {
        uVar3 = uVar8 + 1;
        local_8c[uVar8] = 0x20;
        uVar8 = uVar8 + 2 & 0xffff;
        local_8c[uVar3 & 0xffff] = 0x7c;
      }
    }
    *pbVar10 = 0x20;
    uVar5 = uVar8 + 1 & 0xffff;
    uVar7 = uVar4;
    for (uVar3 = uVar5; uVar3 != (uVar8 + iVar6 & 0xffff); uVar3 = uVar3 + 1 & 0xffff) {
      bVar2 = 0x20;
      if (uVar7 < (size & 0xffff)) {
        bVar2 = *(byte *)((int)buf + uVar7);
        if ((0x7e < bVar2) || (((&_ctype_)[bVar2] & 0x97) == 0)) {
          bVar2 = 0x2e;
        }
      }
      local_8c[uVar3] = bVar2;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar7 = (uint)(uVar4 < 0xfff0) * 0x10 + uVar5 & 0xffff;
    local_8c[uVar7] = 0x20;
    local_8c[uVar7 + 1 & 0xffff] = 0x7c;
    local_8c[uVar7 + 2 & 0xffff] = 0;
    log_write(level,tag,"%s");
  }
  memset(local_8c,0x2d,0x48);
  line[0x44] = '\0';
  log_write(level,tag,"%s");
  return;
}

