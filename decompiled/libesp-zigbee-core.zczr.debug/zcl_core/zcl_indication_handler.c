/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_indication_handler(int param_1)

{
  int unaff_s0;
  int iVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
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
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x96,
                  "zcl_indication_handler",&_L0);
  }
  else {
    unaff_s0 = zcl_packet_init_with_msg(&uStack_38,param_1);
    if (unaff_s0 != 0) {
      iVar1 = 0xfe;
      goto _L0;
    }
  }
  iVar1 = core_globals_get();
  if ((*(int *)(iVar1 + 0xd18) != 0) && (iVar1 = zcl_raw_frame_handler(&uStack_38), iVar1 != 0)) {
    return unaff_s0;
  }
  iVar1 = zcl_packet_is_acceptable(&uStack_38);
  if ((iVar1 == 0) && (iVar1 = zcl_packet_handler(&uStack_38), iVar1 == 0)) {
    return 0;
  }
_L0:
  if (iVar1 != 0xfe) {
    iVar1 = zcl_packet_send_default_response(&uStack_38,iVar1);
  }
  return iVar1;
}

