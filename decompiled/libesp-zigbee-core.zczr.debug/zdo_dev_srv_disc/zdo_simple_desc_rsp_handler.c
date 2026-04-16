/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_simple_desc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_simple_desc_rsp_handler(zdo_packet_t *packet)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  undefined1 auStack_28 [4];
  zdp_simple_desc_rsp_field_t rsp;
  
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.length = '\0';
  rsp._5_3_ = 0;
  rsp.desc.ep_id = '\0';
  rsp.desc._1_1_ = 0;
  rsp.desc.app_profile_id = 0;
  rsp.desc.app_device_id = 0;
  rsp.desc._6_1_ = 0;
  rsp.desc.app_input_cluster_count = '\0';
  rsp.desc.app_output_cluster_count = '\0';
  rsp.desc._9_3_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_simple_desc_rsp(packet->payload,(zdp_simple_desc_rsp_field_t *)auStack_28,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      zVar1 = zdo_cb_simple_desc_rsp((zdp_simple_desc_rsp_field_t *)auStack_28,&packet->ctx);
    }
    else {
      zVar1 = 0xfe;
    }
  }
  if (rsp.desc._8_4_ != 0) {
    mm_free();
  }
  return zVar1;
}

