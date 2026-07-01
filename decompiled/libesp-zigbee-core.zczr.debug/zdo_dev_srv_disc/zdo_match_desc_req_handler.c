/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_match_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Removing unreachable block (ram,0x00011ffc) */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_match_desc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  zdp_status_t zVar1;
  uint8_t uVar2;
  undefined2 uVar3;
  undefined3 extraout_var;
  uint uVar4;
  undefined3 extraout_var_00;
  int iVar5;
  uint uVar6;
  undefined1 auStack_68 [64];
  undefined1 auStack_28 [4];
  zdp_match_desc_rsp_field_t rsp;
  zdp_match_desc_req_field_t req;
  
  rsp.match_list = (uint8_t *)0x0;
  auStack_28 = (undefined1  [4])0x0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.match_length = '\0';
  rsp._5_3_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_match_desc_req
                      (packet->payload,(zdp_match_desc_req_field_t *)&rsp.match_list,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      auStack_28 = (undefined1  [4])((uint)auStack_28 & 0xffffff00);
      uVar3 = (ushort)rsp.match_list;
      if (0xfff7 < ((uint)rsp.match_list & 0xffff)) {
        uVar3 = nwk_get_short_address();
      }
      auStack_28._2_2_ = uVar3;
      rsp._0_4_ = rsp._0_4_ & 0xffffff00;
      memset(auStack_68,0,0x40);
      uVar6 = (uint)rsp.match_list & 0xffff;
      rsp._4_4_ = auStack_68;
      uVar4 = nwk_get_short_address();
      if ((uVar6 == uVar4) || (0xfff7 < ((uint)rsp.match_list & 0xffff))) {
        uVar2 = zdo_match_desc_add_matched_ep_ids
                          ((zdp_match_desc_req_field_t *)&rsp.match_list,
                           (zdp_match_desc_rsp_field_t *)auStack_28);
        rsp.status = uVar2;
        if ((CONCAT31(extraout_var_00,uVar2) == 0) && (0xfff7 < (ushort)rsp.match_list)) {
          return 0xfe;
        }
        auStack_28 = (undefined1  [4])((uint)auStack_28 & 0xffffff00);
      }
      else {
        iVar5 = nwk_is_device_zed();
        if (iVar5 == 0) {
          auStack_28[0] = 0x81;
          iVar5 = 0;
          do {
            iVar5 = nwk_child_table_next(iVar5);
            if (iVar5 == 0) goto _L0;
          } while (((*(uint *)(iVar5 + 0xc) & 0x3c0) != 0x40) ||
                  (uVar6 = (uint)rsp.match_list & 0xffff, uVar4 = nwk_neighbor_get_shortaddr(iVar5),
                  uVar6 != uVar4));
          auStack_28[0] = 0x89;
        }
        else {
          if (0xfff7 < packet->dst_addr) {
            return 0xfe;
          }
          auStack_28[0] = 0x80;
        }
      }
_L0:
      zVar1 = zdo_op_match_desc_rsp(resp->payload,(zdp_match_desc_rsp_field_t *)auStack_28,true);
    }
    else {
      zVar1 = 0xfe;
    }
  }
  return zVar1;
}

