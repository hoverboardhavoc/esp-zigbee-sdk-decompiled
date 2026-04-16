/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> ezb_zcl_electrical_meas_get_meas_prof_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_electrical_meas_get_meas_prof_cmd_req
                    (ezb_zcl_electrical_measurement_get_meas_prof_cmd_t *cmd_req)

{
  int iVar1;
  uint32_t auStack_3c [2];
  zcl_packet_t packet;
  
  auStack_3c[1] = 0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  if (cmd_req == (ezb_zcl_electrical_measurement_get_meas_prof_cmd_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_3c + 1,0);
    if ((iVar1 == 0) &&
       (iVar1 = zcl_cmd_to_packet(auStack_3c + 1,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,1,0xb04),
       iVar1 == 0)) {
      auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).attr_id);
      iVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
      if (iVar1 == 0) {
        auStack_3c[0] = (cmd_req->payload).start_time;
        iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
        if (iVar1 == 0) {
          auStack_3c[0] = CONCAT31(auStack_3c[0]._1_3_,(cmd_req->payload).num_of_intervals);
          iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
          if (iVar1 == 0) {
            zcl_packet_send(auStack_3c + 1,&(cmd_req->cmd_ctrl).cnf_ctx);
            iVar1 = zcl_status_to_err();
            if (iVar1 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  zcl_packet_free(auStack_3c + 1);
  return iVar1;
}

