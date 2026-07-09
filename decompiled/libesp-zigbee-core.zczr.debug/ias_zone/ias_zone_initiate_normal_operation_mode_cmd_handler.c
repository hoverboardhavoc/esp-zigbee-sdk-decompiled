/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_initiate_normal_operation_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_initiate_normal_operation_mode_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xcc,
                  "ias_zone_initiate_normal_operation_mode_cmd_handler","packet && rsp");
  }
  else {
    iVar1 = validate_cie_establishment(*(undefined1 *)(param_1 + 0x15));
    if (iVar1 == 0) {
      uVar3 = 0x7e;
      goto _L0;
    }
  }
  iVar1 = validate_cie_authorization(*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2));
  if (iVar1 == 0) {
    uVar3 = 0x7e;
  }
  else {
    uVar3 = zcl_packet_to_message(&uStack_28,param_1);
    if (uVar3 == 0) {
      uStack_24._0_3_ = CONCAT12(0xfe,(undefined2)uStack_24);
      zcl_core_action_schedule(0x30,&uStack_28);
      uVar3 = uStack_24 >> 0x10 & 0xff;
      if (uVar3 != 0xfe) {
        puVar2 = (undefined1 *)ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
        iVar1 = milli_timer_is_running(puVar2 + 4);
        if (iVar1 != 0) {
          milli_timer_stop(puVar2 + 4);
        }
        iVar1 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x13);
        if (iVar1 != 0) {
          if (puVar2[1] != '\0') {
            **(undefined1 **)(iVar1 + 8) = *puVar2;
            puVar2[1] = 0;
          }
          goto _L0;
        }
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xd9,
                      "ias_zone_initiate_normal_operation_mode_cmd_handler","attr_desc");
      }
      uVar3 = 1;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar3);
  return;
}

