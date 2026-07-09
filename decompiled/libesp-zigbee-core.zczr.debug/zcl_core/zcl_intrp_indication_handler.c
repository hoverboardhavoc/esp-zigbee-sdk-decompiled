/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_intrp_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_intrp_indication_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iVar1 = zcl_packet_init_with_intrp_ind(&uStack_38,param_1);
  if (iVar1 == 0) {
    if ((uStack_20 & 0xffff) == 0xc05e) {
      iVar1 = zcl_touchlink_handler(&uStack_38);
      if (iVar1 == 0) {
        return;
      }
    }
    else {
      iVar1 = 0x85;
    }
  }
  else {
    iVar1 = 0xfe;
  }
  if (iVar1 != 0xfe) {
    zcl_packet_send_default_response(&uStack_38,iVar1);
  }
  return;
}

