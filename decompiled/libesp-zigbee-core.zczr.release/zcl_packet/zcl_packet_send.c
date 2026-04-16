/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000106e8) */
/* WARNING: Removing unreachable block (ram,0x00010744) */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_send(zcl_packet_t *packet,zcl_packet_cnf_ctx_t *cnf_ctx)

{
  zcl_status_t zVar1;
  uint16_t uVar2;
  uint uVar3;
  undefined2 extraout_var;
  int iVar4;
  zcl_packet_payload_t *pzStack_44;
  undefined1 auStack_40 [10];
  undefined2 uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  undefined4 uStack_30;
  uint uStack_2c;
  ezb_af_user_cnf_callback_t p_Stack_28;
  void *pvStack_24;
  
  if (packet != (zcl_packet_t *)0x0) {
    zcl_frame_fill_header(packet);
    uVar3 = zmsg_get_length(packet->payload);
    uVar2 = zcl_packet_max_available_space
                      ((packet->header).cluster_id,false,
                       (_Bool)((byte)(*(ushort *)&(packet->header).fc >> 2) & 1));
    zVar1 = 0x89;
    if (uVar3 <= CONCAT22(extraout_var,uVar2)) {
      pzStack_44 = packet->payload;
      packet->payload = (zcl_packet_payload_t *)0x0;
      uStack_30 = 0;
      uStack_2c = 0;
      p_Stack_28 = (ezb_af_user_cnf_callback_t)0x0;
      pvStack_24 = (void *)0x0;
      memcpy(auStack_40,&(packet->header).dst_addr,10);
      uStack_34 = (packet->header).cluster_id;
      uStack_32 = (packet->header).profile_id;
      uStack_36._0_1_ = (packet->header).src_ep;
      uStack_36._1_1_ = (packet->header).dst_ep;
      uStack_2c._0_1_ = (byte)uStack_2c | 2;
      iVar4 = zcl_cluster_fragment_is_supported();
      uStack_2c = CONCAT31(uStack_2c._1_3_,(byte)uStack_2c & 0xf3 | (byte)(iVar4 << 2) & 0xc) &
                  0xffffffef;
      if (cnf_ctx == (zcl_packet_cnf_ctx_t *)0x0) {
        p_Stack_28 = (ezb_af_user_cnf_callback_t)0x0;
        pvStack_24 = (void *)0x0;
      }
      else {
        p_Stack_28 = cnf_ctx->cb;
        pvStack_24 = cnf_ctx->user_ctx;
      }
      af_data_request(&pzStack_44);
      zVar1 = err_to_zcl_status();
    }
    return zVar1;
  }
  return '\x01';
}

