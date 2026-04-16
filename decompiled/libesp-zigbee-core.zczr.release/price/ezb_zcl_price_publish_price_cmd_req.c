/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> ezb_zcl_price_publish_price_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_price_publish_price_cmd_req(ezb_zcl_price_publish_price_cmd_t *cmd_req)

{
  int iVar1;
  ezb_err_t eVar2;
  uint uVar3;
  undefined1 auStack_50 [22];
  uint16_t uStack_3a;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if (cmd_req == (ezb_zcl_price_publish_price_cmd_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,0);
    if (iVar1 == 0) {
      memcpy(auStack_50,cmd_req,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,1,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,0x700);
      if (iVar1 == 0) {
        eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).provider_id);
        if (eVar2 == 0) {
          uVar3 = (uint)(cmd_req->payload).rate_label[0];
          iVar1 = 2;
          if (0xc < uVar3) goto _L0;
          iVar1 = zmsg_append_bytes(packet._32_4_,uVar3 + 1,(cmd_req->payload).rate_label);
          if ((((iVar1 == 0) &&
               (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,
                                         (uint)*(byte *)((int)&(cmd_req->payload).issuer_event_id +
                                                        3) << 0x18 |
                                         *(uint *)((cmd_req->payload).rate_label + 0xc) >> 8),
               eVar2 == 0)) &&
              (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,
                                        (uint)*(byte *)((int)&(cmd_req->payload).current_time + 3)
                                        << 0x18 | *(uint *)((int)&(cmd_req->payload).issuer_event_id
                                                           + 3) >> 8), eVar2 == 0)) &&
             (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).unit_of_measure),
             eVar2 == 0)) {
            uStack_3a = (cmd_req->payload).currency;
            iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
            if (((iVar1 == 0) &&
                (uVar3 = *(uint *)&(cmd_req->payload).field_0x1c,
                eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                       (byte)((uVar3 & 0xf) << 4) | (byte)(uVar3 >> 4) & 0xf),
                eVar2 == 0)) &&
               ((uVar3 = *(uint *)&(cmd_req->payload).field_0x1c,
                eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                       (byte)(uVar3 >> 4) & 0xf0 | (byte)(uVar3 >> 0xc) & 0xf),
                eVar2 == 0 &&
                (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).start_time),
                eVar2 == 0)))) {
              uStack_3a = (cmd_req->payload).duration_in_minutes;
              iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
              if ((((iVar1 == 0) &&
                   (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).price),
                   eVar2 == 0)) &&
                  ((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).price_ratio),
                   eVar2 == 0 &&
                   (((((eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,
                                                 (uint)*(byte *)((int)&(cmd_req->payload).
                                                                       generation_price + 3) << 0x18
                                                 | *(uint *)&(cmd_req->payload).price_ratio >> 8),
                       eVar2 == 0 &&
                       (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                               (cmd_req->payload).generation_price_ratio),
                       eVar2 == 0)) &&
                      (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,
                                                (cmd_req->payload).alternate_cost_delivered),
                      eVar2 == 0)) &&
                     (((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                               (cmd_req->payload).alternate_cost_unit), eVar2 == 0
                       && (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                                  (cmd_req->payload).alternate_cost_trailing_digit),
                          eVar2 == 0)) &&
                      ((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                               (cmd_req->payload).number_of_block_thresholds),
                       eVar2 == 0 &&
                       ((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                                (cmd_req->payload).price_control), eVar2 == 0 &&
                        (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                                (cmd_req->payload).number_of_generation_tiers),
                        eVar2 == 0)))))))) &&
                    (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                            (cmd_req->payload).generation_tier), eVar2 == 0)))))) &&
                 (((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                           (cmd_req->payload).extended_number_of_price_tiers),
                   eVar2 == 0 &&
                   (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                           (cmd_req->payload).extended_price_tier), eVar2 == 0)) &&
                  (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                          (cmd_req->payload).extended_register_tier), eVar2 == 0))))
              {
                zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
                iVar1 = zcl_status_to_err();
                if (iVar1 == 0) {
                  return 0;
                }
                goto _L0;
              }
            }
          }
        }
        iVar1 = 1;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}

