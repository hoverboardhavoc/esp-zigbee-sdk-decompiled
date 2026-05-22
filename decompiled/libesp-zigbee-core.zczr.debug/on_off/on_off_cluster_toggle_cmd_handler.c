/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_toggle_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t on_off_cluster_toggle_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  bool cmd_id;
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  short *psVar4;
  char *pcVar5;
  short sVar6;
  
  ep_id = (packet->header).dst_ep;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x176,
                  "on_off_cluster_toggle_cmd_handler","packet && rsp");
  }
  else {
    pzVar2 = on_off_srv_get_attr_desc(ep_id,0);
    if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      cmd_id = *pzVar2->data_p == '\0';
      on_off_process_transition(ep_id,cmd_id,cmd_id,0,0);
      eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
      return eVar1;
    }
  }
  pcVar5 = "on_off_cluster_toggle_cmd_handler";
  psVar4 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c"
                                  ,0x178,"on_off_cluster_toggle_cmd_handler","attr_desc");
  iVar3 = zmsg_read_bytes(*psVar4,1,pcVar5);
  if (iVar3 == 0) {
    sVar6 = -1;
  }
  else {
    sVar6 = *psVar4 + (short)iVar3;
  }
  *psVar4 = sVar6;
  return (ezb_zcl_status_t)iVar3;
}

