/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  uint8_t uVar1;
  zdp_status_t zVar2;
  undefined3 extraout_var;
  uint uVar3;
  undefined3 extraout_var_00;
  int iVar4;
  void *__src;
  uint uVar5;
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
    iVar4 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    iVar4 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    iVar4 = 0xfe;
  }
  else {
    zVar2 = zdo_op_simple_desc_req
                      (packet->payload,(zdp_simple_desc_req_field_t *)&rsp.desc.app_cluster_list,
                       false);
    if (CONCAT31(extraout_var,zVar2) == 0) {
      uVar5 = (uint)rsp.desc.app_cluster_list & 0xffff;
      if (uVar5 < 0xfff8) {
        auStack_2c._2_2_ = (ezb_shortaddr_t)rsp.desc.app_cluster_list;
        uVar3 = nwk_get_short_address();
        if (uVar5 == uVar3) {
          if ((((uint)rsp.desc.app_cluster_list >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
            __src = (void *)af_get_simple_desc();
            uVar1 = '\0';
            if (__src == (void *)0x0) {
              uVar1 = 0x83;
            }
            auStack_2c[0] = uVar1;
            if (uVar1 == '\0') {
              memcpy(&rsp.length,__src,0x10);
            }
          }
          else {
            auStack_2c[0] = 0x82;
          }
        }
        else {
          auStack_2c[0] = 0x80;
          iVar4 = nwk_is_device_zczr();
          if (iVar4 != 0) {
            auStack_2c[0] = 0x81;
            iVar4 = 0;
            do {
              iVar4 = nwk_child_table_next(iVar4);
              if (iVar4 == 0) goto _L0;
            } while (((*(uint *)(iVar4 + 0xc) & 0x3c0) != 0x40) ||
                    (uVar3 = (uint)rsp.desc.app_cluster_list & 0xffff,
                    uVar5 = nwk_neighbor_get_shortaddr(iVar4), uVar3 != uVar5));
            auStack_2c[0] = 0x89;
          }
        }
_L0:
        zVar2 = zdo_op_simple_desc_rsp(resp->payload,(zdp_simple_desc_rsp_field_t *)auStack_2c,true)
        ;
        iVar4 = CONCAT31(extraout_var_00,zVar2);
        if (iVar4 != 0) {
          iVar4 = 0xfe;
        }
      }
      else {
        iVar4 = 0xfe;
      }
    }
    else {
      iVar4 = 0xfe;
    }
  }
  return (zdp_status_t)iVar4;
}

