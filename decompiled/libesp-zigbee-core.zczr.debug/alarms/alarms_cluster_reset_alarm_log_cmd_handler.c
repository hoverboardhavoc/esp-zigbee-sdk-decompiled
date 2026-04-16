/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_reset_alarm_log_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_reset_alarm_log_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  int iVar3;
  ezb_err_t eVar4;
  int extraout_a1;
  uint unaff_s2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  uint uStack_34;
  
  if ((packet != (zcl_packet_t *)0x0) && (rsp != (zcl_packet_t *)0x0)) {
    alarm_table_reset((packet->header).dst_ep);
    eVar2 = zcl_packet_setup_default_response(rsp,packet,0);
    return eVar2;
  }
  iVar3 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/alarms.c",500,
                        "alarms_cluster_reset_alarm_log_cmd_handler","packet && rsp");
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_38 = 0;
  uStack_34 = 0;
  if ((iVar3 == 0) || (extraout_a1 == 0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1e7,
                  "alarms_cluster_reset_all_alarms_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&uStack_40,iVar3);
    if (unaff_s2 != 0) goto _L0;
  }
  uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
  iStack_38 = iVar3;
  zcl_core_action_schedule(0x36,&uStack_40);
  uVar1 = uStack_34 & 0xff;
  if ((uStack_34 & 0xff) == 0xfe) {
    uVar1 = unaff_s2;
  }
  unaff_s2 = uVar1;
  eVar4 = alarm_table_reset(*(uint8_t *)(iVar3 + 0x15));
  if (eVar4 == 0) {
    if ((char)uStack_34 == -2) {
      unaff_s2 = 1;
    }
  }
  else {
    unaff_s2 = 0x8b;
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(extraout_a1,iVar3,unaff_s2);
  return eVar2;
}

