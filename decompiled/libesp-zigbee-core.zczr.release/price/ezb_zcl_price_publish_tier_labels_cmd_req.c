/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> ezb_zcl_price_publish_tier_labels_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_price_publish_tier_labels_cmd_req
                    (ezb_zcl_price_publish_tier_labels_cmd_t *cmd_req)

{
  uint8_t val;
  int iVar1;
  ezb_err_t eVar2;
  uint uVar3;
  ezb_zcl_price_tier_label_entry_t *peVar4;
  uint uVar5;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  memset(auStack_48,0,0x28);
  if ((cmd_req == (ezb_zcl_price_publish_tier_labels_cmd_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_48,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,cmd_req,10);
    iVar1 = zcl_cmd_to_packet(auStack_48,1,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,8,0x700);
    if (iVar1 == 0) {
      eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).provider_id);
      if ((((eVar2 == 0) &&
           (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).issuer_event_id),
           eVar2 == 0)) &&
          (eVar2 = zmsg_append_le32((zmsg_t *)packet._32_4_,(cmd_req->payload).issuer_tariff_id),
          eVar2 == 0)) &&
         ((eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).command_index),
          eVar2 == 0 &&
          (eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                  (cmd_req->payload).total_number_of_commands), eVar2 == 0)))) {
        val = (cmd_req->payload).number_of_labels;
        if ((val == '\0') ||
           ((cmd_req->payload).tier_labels == (ezb_zcl_price_tier_label_entry_t *)0x0)) {
_L0:
          iVar1 = 2;
          goto _L0;
        }
        eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,val);
        if (eVar2 == 0) {
          for (uVar5 = 0; uVar5 < (cmd_req->payload).number_of_labels; uVar5 = uVar5 + 1 & 0xff) {
            eVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,
                                   (cmd_req->payload).tier_labels[uVar5].tier_id);
            if (eVar2 != 0) goto _L0;
            peVar4 = (cmd_req->payload).tier_labels;
            uVar3 = (uint)peVar4[uVar5].tier_label[0];
            if (0xc < uVar3) goto _L0;
            iVar1 = zmsg_append_bytes(packet._32_4_,uVar3 + 1,peVar4[uVar5].tier_label);
            if (iVar1 != 0) goto _L0;
          }
          zcl_packet_send(auStack_48,&(cmd_req->cmd_ctrl).cnf_ctx);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
_L0:
      iVar1 = 1;
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}

