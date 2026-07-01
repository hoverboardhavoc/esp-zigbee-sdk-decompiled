/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_addr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_addr_rsp_handler(zdo_packet_t *packet)

{
  zdp_status_t zVar1;
  zdo_packet_payload_t *payload;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_28 [4];
  zdp_nwk_addr_rsp_field_t rsp;
  
  auStack_28 = (undefined1  [4])0x0;
  rsp._0_4_ = 0;
  rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
  rsp._8_4_ = 0;
  rsp.num_assoc_dev = '\0';
  rsp.start_index = '\0';
  rsp._14_2_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
_L0:
    zVar1 = 0xfe;
  }
  else {
    payload = packet->payload;
    if (payload == (zdo_packet_payload_t *)0x0) {
      zVar1 = 0xfe;
      goto _L0;
    }
    if (packet->cluster_id == 0x8000) {
      zVar1 = zdo_op_nwk_addr_rsp(payload,'\x02',(zdp_nwk_addr_rsp_field_t *)auStack_28,false);
      if (CONCAT31(extraout_var_00,zVar1) != 0) {
        zVar1 = 0xfe;
        goto _L0;
      }
    }
    else {
      if (packet->cluster_id != 0x8001) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1dc,
                      "zdo_addr_rsp_handler",&_LC5);
        goto _L0;
      }
      zVar1 = zdo_op_ieee_addr_rsp(payload,'\x02',(zdp_ieee_addr_rsp_field_t *)auStack_28,false);
      if (CONCAT31(extraout_var,zVar1) != 0) {
        zVar1 = 0xfe;
        goto _L0;
      }
    }
    rsp.nwk_addr_assoc_dev_list._2_2_ = 0;
    nwk_address_update(auStack_28 + 1,(uint)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ >> 0x10,
                       (undefined1 *)((int)&rsp.nwk_addr_assoc_dev_list + 2));
    zVar1 = zdo_cb_address_rsp((zdp_address_rsp_field_t *)auStack_28,&packet->ctx);
  }
_L0:
  if (rsp._12_4_ != 0) {
    mm_free();
  }
  return zVar1;
}

