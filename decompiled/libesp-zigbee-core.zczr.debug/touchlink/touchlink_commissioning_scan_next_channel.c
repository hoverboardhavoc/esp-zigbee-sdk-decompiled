/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_scan_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_commissioning_scan_next_channel(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  byte local_20 [20];
  
  local_20[0xc] = 0xb;
  local_20[0xd] = 0xf;
  local_20[0xe] = 0x14;
  local_20[0xf] = 0x19;
  local_20[0] = 0xc;
  local_20[1] = 0xd;
  local_20[2] = 0xe;
  local_20[3] = 0x10;
  local_20[4] = 0x11;
  local_20[5] = 0x12;
  local_20[6] = 0x13;
  local_20[7] = 0x15;
  local_20[8] = 0x16;
  local_20[9] = 0x17;
  local_20[10] = 0x18;
  local_20[0xb] = 0x1a;
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
    iVar4 = touchlink_commissioning_get();
    uVar3 = (uint)local_20[uVar1 + 0xc];
    if ((*(uint *)(iVar4 + 0x10) & 1 << (uVar3 & 0x1f)) != 0) {
      iVar4 = 0;
      goto _L0;
    }
  }
  iVar4 = touchlink_commissioning_get();
  *(undefined1 *)(iVar4 + 0xc) = 0;
  for (uVar1 = 0; uVar1 < 0xc; uVar1 = uVar1 + 1 & 0xff) {
    iVar4 = touchlink_commissioning_get();
    uVar3 = (uint)local_20[uVar1];
    if ((*(uint *)(iVar4 + 0x10) & 1 << (uVar3 & 0x1f)) != 0) goto _L0;
  }
  uVar3 = 0xb;
  iVar4 = 5;
_L0:
  if (iVar4 == 0) {
_L0:
    iVar4 = touchlink_commissioning_get();
    if (*(char *)(iVar4 + 0xc) == '\0') {
      uVar2 = 1;
    }
    else {
      iVar4 = touchlink_commissioning_get();
      if (*(char *)(iVar4 + 0xc) == '\x05') {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    iVar4 = touchlink_commissioning_get();
    if (*(char *)(iVar4 + 0xc) != '\0') {
      iVar4 = touchlink_commissioning_get();
      *(char *)(iVar4 + 0xc) = *(char *)(iVar4 + 0xc) + -1;
    }
    iVar4 = touchlink_commissioning_get();
    if (*(char *)(iVar4 + 0xc) == '\0') {
      iVar4 = touchlink_commissioning_get();
      *(uint *)(iVar4 + 0x10) = ~(1 << (uVar3 & 0x1f)) & *(uint *)(iVar4 + 0x10);
    }
    touchlink_set_intrp_channel(uVar3);
    iVar4 = touchlink_commissioning_get();
    uVar2 = touchlink_send_scan_req(uVar2,iVar4 + 0x10);
  }
  else {
    iVar4 = touchlink_commissioning_get();
    *(undefined1 *)(iVar4 + 0xc) = 0;
    iVar4 = touchlink_commissioning_get();
    *(undefined4 *)(iVar4 + 0x10) = 0;
    uVar2 = 5;
  }
  return uVar2;
}

