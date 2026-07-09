/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_initiate_test_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_initiate_test_mode_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xea,
                  "ias_zone_initiate_test_mode_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 3);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < auStack_22[0]) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  iVar2 = validate_cie_establishment(*(undefined1 *)(param_1 + 0x15));
  if (iVar2 == 0) {
    uVar1 = 0x7e;
  }
  else {
    iVar2 = validate_cie_authorization(*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2))
    ;
    if (iVar2 == 0) {
      uVar1 = 0x7e;
    }
    else {
      puVar3 = (undefined1 *)ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
      iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x13);
      if (iVar2 == 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xf4,
                      "ias_zone_initiate_test_mode_cmd_handler","attr_desc");
      }
      else {
        *puVar3 = **(undefined1 **)(iVar2 + 8);
        **(undefined1 **)(iVar2 + 8) = uStack_28._3_1_;
        uVar1 = zcl_packet_to_message(&uStack_2c,param_1);
        if (uVar1 != 0) goto _L0;
        uStack_24 = CONCAT11(uStack_24._1_1_,0xfe);
        zcl_core_action_schedule(0x2f,&uStack_2c);
        uVar1 = (uint)(byte)uStack_24;
        if (uVar1 != 0xfe) {
          if (uVar1 == 0) {
            puVar3[1] = 1;
            milli_timer_init(puVar3 + 4,ias_zone_restore_normal_operation_mode,
                             *(undefined1 *)(param_1 + 0x15));
            milli_timer_start(puVar3 + 4,(uStack_28 >> 0x10 & 0xff) * 1000);
          }
          goto _L0;
        }
      }
      **(undefined1 **)(iVar2 + 8) = *puVar3;
      uVar1 = 1;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

