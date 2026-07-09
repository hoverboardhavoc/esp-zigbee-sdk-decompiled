/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_enroll_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_enroll_rsp_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x99,
                  "ias_zone_enroll_rsp_cmd_handler","packet && rsp");
_L0:
    iVar2 = validate_cie_authorization(*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2))
    ;
    if (iVar2 == 0) {
      uVar1 = 0x7e;
      goto _L0;
    }
    iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x11);
    **(undefined1 **)(iVar2 + 8) = uStack_1c._1_1_;
    iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0);
    **(undefined1 **)(iVar2 + 8) = 1;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_1c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_1c + 1);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_12) {
      uVar1 = 0x80;
      goto _L0;
    }
    if ((uStack_1c & 0xff) == 0) {
      iVar2 = validate_cie_establishment(*(undefined1 *)(param_1 + 0x15));
      if (iVar2 == 0) {
        uVar1 = 0x7e;
        goto _L0;
      }
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_28,param_1);
  if (uVar1 == 0) {
    uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
    iStack_20 = param_1;
    zcl_core_action_schedule(0x32,&uStack_28);
    if ((uStack_18 & 0xff) != 0xfe) {
      uVar1 = uStack_18 & 0xff;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

