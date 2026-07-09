/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_scan_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_commissioning_scan_next_channel(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte local_40 [28];
  
  local_40[0] = 0xb;
  local_40[1] = 0xf;
  local_40[2] = 0x14;
  local_40[3] = 0x19;
  iVar5 = 0;
  memcpy(local_40 + 4,&_L0,0xc);
  do {
    iVar3 = core_globals_get();
    uVar2 = (uint)local_40[iVar5];
    if ((1 << (uVar2 & 0x1f) & *(uint *)(iVar3 + 0x13bc)) != 0) goto _L0;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0x13b8) = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar2 = (uint)(local_40 + 4)[iVar5];
    if ((1 << (uVar2 & 0x1f) & *(uint *)(iVar3 + 0x13bc)) != 0) break;
    iVar5 = iVar5 + 1;
    if (iVar5 == 0xc) {
      iVar5 = core_globals_get();
      *(undefined1 *)(iVar5 + 0x13b8) = 0;
      iVar5 = core_globals_get();
      *(undefined4 *)(iVar5 + 0x13bc) = 0;
      return 5;
    }
  }
_L0:
  iVar5 = core_globals_get();
  bVar1 = true;
  if (*(char *)(iVar5 + 0x13b8) != '\0') {
    iVar5 = core_globals_get();
    bVar1 = *(char *)(iVar5 + 0x13b8) == '\x05';
  }
  iVar5 = core_globals_get();
  if (*(char *)(iVar5 + 0x13b8) != '\0') {
    iVar5 = core_globals_get();
    *(char *)(iVar5 + 0x13b8) = *(char *)(iVar5 + 0x13b8) + -1;
  }
  iVar5 = core_globals_get();
  if (*(char *)(iVar5 + 0x13b8) == '\0') {
    iVar5 = core_globals_get();
    *(uint *)(iVar5 + 0x13bc) = ~(1 << (uVar2 & 0x1f)) & *(uint *)(iVar5 + 0x13bc);
  }
  touchlink_set_intrp_channel(uVar2);
  iVar5 = core_globals_get();
  uVar4 = touchlink_send_scan_req(bVar1,iVar5 + 0x13bc);
  return uVar4;
}

