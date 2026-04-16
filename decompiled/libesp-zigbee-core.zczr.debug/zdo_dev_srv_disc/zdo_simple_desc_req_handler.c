/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_simple_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_simple_desc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined3 extraout_var_00;
  void *__src;
  uint8_t uVar5;
  uint uVar6;
  undefined1 auStack_2c [4];
  zdp_simple_desc_rsp_field_t rsp;
  zdp_simple_desc_req_field_t req;
  
  rsp.desc.app_cluster_list = (uint16_t *)0x0;
  auStack_2c[0] = '\0';
  auStack_2c[1] = 0;
  auStack_2c._2_2_ = 0;
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
    iVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    iVar3 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    iVar3 = 0xfe;
  }
  else {
    zVar1 = zdo_op_simple_desc_req
                      (packet->payload,(zdp_simple_desc_req_field_t *)&rsp.desc.app_cluster_list,
                       false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      uVar6 = (uint)rsp.desc.app_cluster_list & 0xffff;
      if (uVar6 < 0xfff8) {
        auStack_2c._2_2_ = (ezb_shortaddr_t)rsp.desc.app_cluster_list;
        uVar2 = nwk_get_short_address();
        if (uVar6 == uVar2) {
          if ((((uint)rsp.desc.app_cluster_list >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
            __src = (void *)af_get_simple_desc();
            uVar5 = '\0';
            if (__src == (void *)0x0) {
              uVar5 = 0x83;
            }
            auStack_2c[0] = uVar5;
            if (uVar5 == '\0') {
              memcpy(&rsp.length,__src,0x10);
            }
          }
          else {
            auStack_2c[0] = 0x82;
          }
        }
        else {
          iVar3 = nwk_is_device_zed();
          puVar4 = (undefined2 *)0x0;
          if (iVar3 != 0) {
            iVar3 = 0xfe;
            goto _L0;
          }
          while (puVar4 = (undefined2 *)nwk_neighbor_table_next(puVar4), puVar4 != (undefined2 *)0x0
                ) {
            if ((*(uint *)(puVar4 + 6) & 3) == 2) {
              nwk_address_short_by_ref(*puVar4,auStack_2c + 2);
              if (auStack_2c._2_2_ == (ezb_shortaddr_t)rsp.desc.app_cluster_list) break;
              auStack_2c._2_2_ = 0xffff;
            }
          }
          if (auStack_2c._2_2_ == 0xffff) {
            uVar5 = 0x81;
          }
          else {
            uVar5 = 0x89;
          }
          auStack_2c[0] = uVar5;
        }
        zVar1 = zdo_op_simple_desc_rsp(resp->payload,(zdp_simple_desc_rsp_field_t *)auStack_2c,true)
        ;
        iVar3 = CONCAT31(extraout_var_00,zVar1);
        if (iVar3 != 0) {
          iVar3 = 0xfe;
        }
      }
      else {
        iVar3 = 0xfe;
      }
    }
    else {
      iVar3 = 0xfe;
    }
  }
_L0:
  return (zdp_status_t)iVar3;
}

