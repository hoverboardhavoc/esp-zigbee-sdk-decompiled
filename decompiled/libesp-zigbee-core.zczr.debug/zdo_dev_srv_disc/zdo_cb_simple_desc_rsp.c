/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_cb_simple_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_cb_simple_desc_rsp(zdp_simple_desc_rsp_field_t *rsp,zdo_packet_ctx_t *ctx)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  zdp_simple_desc_rsp_field_t zStack_38;
  
  if ((rsp != (zdp_simple_desc_rsp_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0)) {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x3af,
                        "zdo_cb_simple_desc_rsp","rsp && ctx");
  zStack_38.status = '\0';
  zStack_38._1_1_ = 0;
  zStack_38.nwk_addr_of_interest = 0;
  zStack_38.length = '\0';
  zStack_38._5_3_ = 0;
  zStack_38.desc.ep_id = '\0';
  zStack_38.desc._1_1_ = 0;
  zStack_38.desc.app_profile_id = 0;
  zStack_38.desc.app_device_id = 0;
  zStack_38.desc._6_1_ = 0;
  zStack_38.desc.app_input_cluster_count = '\0';
  zStack_38.desc.app_output_cluster_count = '\0';
  zStack_38.desc._9_3_ = 0;
  zStack_38.desc.app_cluster_list = (uint16_t *)0x0;
  if (iVar2 == 0) {
    zVar1 = 0xfe;
  }
  else if (*(zdo_packet_payload_t **)(iVar2 + 0x14) == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_simple_desc_rsp(*(zdo_packet_payload_t **)(iVar2 + 0x14),&zStack_38,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      zVar1 = zdo_cb_simple_desc_rsp(&zStack_38,(zdo_packet_ctx_t *)(iVar2 + 8));
    }
    else {
      zVar1 = 0xfe;
    }
  }
  if (zStack_38.desc.app_cluster_list != (uint16_t *)0x0) {
    mm_free();
  }
  return zVar1;
}

