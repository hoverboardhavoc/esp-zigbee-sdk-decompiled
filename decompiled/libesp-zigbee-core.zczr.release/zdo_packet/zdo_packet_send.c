/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_send(zdo_packet_t *packet)

{
  uint8_t uVar1;
  code cVar2;
  int iVar3;
  uint16_t uVar4;
  undefined2 extraout_var;
  uint uVar5;
  ezb_af_user_cnf_callback_t p_Var6;
  zdo_packet_user_ctx_t pvVar7;
  zdo_packet_req_callback_t p_Var8;
  zdo_packet_payload_t *pzStack_44;
  af_data_req_t af_req;
  
  if (packet == (zdo_packet_t *)0x0) {
_L0:
    iVar3 = 0x80;
  }
  else {
    uVar4 = zdo_packet_max_available_space(packet->cluster_id);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 <= CONCAT22(extraout_var,uVar4)) {
      if ((short)packet->cluster_id < 0) {
        if ((packet->ctx).mode != '\0') {
          __assert_func(0,0,0,0);
          goto _L0;
        }
      }
      else {
        iVar3 = core_globals_get();
        uVar1 = *(uint8_t *)(iVar3 + 0xca8);
        *(uint8_t *)(iVar3 + 0xca8) = uVar1 + '\x01';
        packet->tsn = uVar1;
      }
      zmsg_prepend_bytes(packet->payload,1,packet);
      uVar1 = packet->tsn;
      cVar2 = (code)(packet->ctx).mode;
      p_Var8 = (packet->ctx).req_ctx.cb;
      pvVar7 = (packet->ctx).req_ctx.arg;
      p_Var6 = (ezb_af_user_cnf_callback_t)calloc(1,0x28);
      if (p_Var6 != (ezb_af_user_cnf_callback_t)0x0) {
        *(zdo_packet_user_ctx_t *)(p_Var6 + 0x20) = pvVar7;
        *p_Var6 = (_func_void_ezb_af_user_cnf_t_ptr_void_ptr)uVar1;
        p_Var6[0x18] = cVar2;
        *(zdo_packet_req_callback_t *)(p_Var6 + 0x1c) = p_Var8;
        p_Var6[0x14] = (_func_void_ezb_af_user_cnf_t_ptr_void_ptr)((byte)p_Var6[0x14] & 0xfc);
        *(ezb_af_user_cnf_callback_t *)(p_Var6 + 0x24) = p_Var6 + 0x24;
        if (cVar2 != (code)0x0) {
          uVar5 = nwk_pim_get_fast_poll_interval();
          nwk_pim_start_fast_poll(5000 / uVar5);
          iVar3 = core_globals_get();
          *(undefined4 *)(p_Var6 + 0x24) = *(undefined4 *)(iVar3 + 0xcac);
          *(ezb_af_user_cnf_callback_t *)(iVar3 + 0xcac) = p_Var6 + 0x24;
          milli_timer_init(zdo_packet_ctx_entry_timeout,p_Var6);
          milli_timer_start(p_Var6 + 4,5000);
        }
        memset(&af_req,0,0x18);
        pzStack_44 = packet->payload;
        packet->payload = (zdo_packet_payload_t *)0x0;
        af_req.data.asdu._0_1_ = 2;
        af_req.data.asdu._2_2_ = packet->dst_addr;
        af_req.data.dst_addr.u._6_2_ = packet->cluster_id;
        af_req.data.radius = '\x02';
        af_req.data._24_4_ = zdo_packet_cnf_handler;
        af_req.cnf_ctx.cb = p_Var6;
        af_data_request(&pzStack_44);
        iVar3 = ezb_err_to_zdp_status();
        if (iVar3 != 0) {
          milli_timer_stop(p_Var6 + 4);
          mm_free(p_Var6);
        }
        goto _L0;
      }
    }
    iVar3 = 0x8a;
  }
_L0:
  return (zdp_status_t)iVar3;
}

