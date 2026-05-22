/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_get_alarm_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_get_alarm_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  alarms_alarm_table_entry_t *unaff_s1;
  int iVar1;
  uint32_t uStack_14;
  
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1a4,
                  "alarms_cluster_get_alarm_cmd_handler","packet && rsp");
_L0:
    uStack_14 = CONCAT31(uStack_14._1_3_,unaff_s1->alarm_code);
    iVar1 = zmsg_append_bytes(rsp->payload,1,&uStack_14);
    if (iVar1 == 0) {
      uStack_14 = CONCAT22(uStack_14._2_2_,unaff_s1->cluster_id);
      iVar1 = zmsg_append_bytes(rsp->payload,2,&uStack_14);
      if (iVar1 == 0) {
        uStack_14 = unaff_s1->time_stamp;
        iVar1 = zmsg_append_bytes(rsp->payload,4,&uStack_14);
        if (iVar1 == 0) goto _L0;
        iVar1 = 0x89;
      }
      else {
        iVar1 = 0x89;
      }
    }
    else {
      iVar1 = 0x89;
    }
  }
  else {
    unaff_s1 = alarm_table_pop_oldest((packet->header).dst_ep);
    if (unaff_s1 == (alarms_alarm_table_entry_t *)0x0) {
      uStack_14 = CONCAT31(uStack_14._1_3_,0x8b);
      iVar1 = zmsg_append_bytes(rsp->payload,1,&uStack_14);
      if (iVar1 == 0) {
_L0:
        iVar1 = zcl_packet_setup_response(rsp,packet,1);
        if (iVar1 == 0) goto _L0;
      }
      else {
        iVar1 = 0x89;
      }
    }
    else {
      uStack_14 = (uint)uStack_14._1_3_ << 8;
      iVar1 = zmsg_append_bytes(rsp->payload,1,&uStack_14);
      if (iVar1 == 0) goto _L0;
      iVar1 = 0x89;
    }
  }
  iVar1 = zcl_packet_setup_default_response(rsp,packet,iVar1);
_L0:
  return (ezb_zcl_status_t)iVar1;
}

