/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_scan_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_scan_next_channel(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  ezb_err_t eVar4;
  int iVar5;
  byte local_40 [4];
  uint8_t primary_channel [4];
  uint8_t secondary_channel [12];
  
  local_40[0] = 0xb;
  local_40[1] = 0xf;
  local_40[2] = 0x14;
  local_40[3] = 0x19;
  iVar5 = 0;
  memcpy(primary_channel,&_L0,0xc);
  do {
    iVar3 = core_globals_get();
    uVar2 = (uint)primary_channel[iVar5 + -4];
    if ((1 << (uVar2 & 0x1f) & *(uint *)(iVar3 + 0x13bc)) != 0) goto _L0;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0x13b8) = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar2 = (uint)primary_channel[iVar5];
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
  eVar4 = touchlink_send_scan_req(bVar1,iVar5 + 0x13bc);
  return eVar4;
}

