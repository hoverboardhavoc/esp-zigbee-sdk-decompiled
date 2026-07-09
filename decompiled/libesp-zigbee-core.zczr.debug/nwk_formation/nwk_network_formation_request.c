/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_network_formation_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_network_formation_request(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xac0) == '\0') {
      iVar1 = nwk_is_joined();
      if ((iVar1 == 0) && (iVar1 = nwk_is_device_zczr(), iVar1 != 0)) {
        if ((((uint)param_1[1] >> 0x19 & 1) == 0) && (iVar1 = nwk_is_device_zc(), iVar1 == 0)) {
          uVar2 = 0x2c2;
        }
        else {
          iVar1 = core_globals_get();
          *(undefined1 *)(iVar1 + 0xac0) = 3;
          iVar1 = core_globals_get();
          nwk_formation_reset_tmp_ctx(iVar1 + 0xac8);
          iVar1 = core_globals_get();
          *(undefined1 *)(iVar1 + 0xacc) = *(undefined1 *)(param_1 + 1);
          iVar1 = core_globals_get();
          *(byte *)(iVar1 + 0xad1) =
               *(byte *)(iVar1 + 0xad1) & 0xfe | (byte)((uint)param_1[1] >> 0x19) & 1;
          uStack_14 = 0;
          local_20 = (uint)*(byte *)(param_1 + 1) << 8;
          uStack_1c = *param_1;
          pcStack_18 = nwk_formation_ed_scan_callback;
          uVar2 = nwk_mm_scan_request(0,&local_20);
        }
      }
      else {
        uVar2 = 0x2c2;
      }
    }
    else {
      uVar2 = 3;
    }
  }
  return uVar2;
}

