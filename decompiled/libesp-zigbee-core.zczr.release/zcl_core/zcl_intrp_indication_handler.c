/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_core.o -> zcl_intrp_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_intrp_indication_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_38 [24];
  short sStack_20;
  
  memset(auStack_38,0,0x28);
  iVar1 = zcl_packet_init_with_intrp_ind(auStack_38,param_1);
  if (iVar1 == 0) {
    iVar1 = 0x85;
    if (sStack_20 == -0x3fa2) {
      iVar1 = zcl_touchlink_handler(auStack_38);
      if (iVar1 == 0) {
        return 0;
      }
      if (iVar1 == 0xfe) goto _L0;
    }
    uVar2 = zcl_packet_send_default_response(auStack_38,iVar1);
  }
  else {
_L0:
    uVar2 = 0xfe;
  }
  return uVar2;
}

