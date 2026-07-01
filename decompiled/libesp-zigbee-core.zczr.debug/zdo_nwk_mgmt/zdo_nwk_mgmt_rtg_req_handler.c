/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_rtg_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  undefined1 auVar1 [4];
  byte bVar2;
  uint8_t uVar3;
  zdp_status_t zVar4;
  uint16_t uVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined3 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 *puVar7;
  undefined1 auStack_1c [4];
  zdp_nwk_mgmt_rtg_rsp_field_t rsp;
  zdp_nwk_mgmt_rtg_req_field_t req;
  uint __nmemb;
  
  rsp.routing_table_list._0_1_ = 0;
  auStack_1c[0] = '\0';
  auStack_1c[1] = '\0';
  auStack_1c[2] = '\0';
  auStack_1c[3] = '\0';
  rsp.status = '\0';
  rsp.routing_table_entries = '\0';
  rsp.start_index = '\0';
  rsp.routing_table_list_count = '\0';
  if (((packet == (zdo_packet_t *)0x0) || (packet->payload == (zdo_packet_payload_t *)0x0)) ||
     (resp == (zdo_packet_t *)0x0)) {
    auStack_1c[0] = 0xfe;
    auStack_1c[1] = '\0';
    auStack_1c[2] = '\0';
    auStack_1c[3] = '\0';
  }
  else if (packet->dst_addr < 0xfff8) {
    zVar4 = zdo_op_nwk_mgmt_rtg_req
                      (packet->payload,(zdp_nwk_mgmt_rtg_req_field_t *)&rsp.routing_table_list,false
                      );
    auStack_1c[0] = zVar4;
    if (CONCAT31(extraout_var,zVar4) == 0) {
      iVar6 = nwk_is_device_zczr();
      if (iVar6 == 0) {
        auStack_1c[0] = 0x84;
      }
      else {
        uVar3 = zdo_nwk_mgmt_rtg_get_entries_capacity();
        __nmemb = CONCAT31(extraout_var_00,uVar3);
        uVar5 = zdo_nwk_mgmt_rtg_get_entries_num();
        if (CONCAT22(extraout_var_01,uVar5) < 0xff) {
          uVar5 = zdo_nwk_mgmt_rtg_get_entries_num();
          uVar3 = (uint8_t)uVar5;
        }
        else {
          uVar3 = 0xff;
        }
        auVar1 = auStack_1c;
        auStack_1c[1] = uVar3;
        auStack_1c[3] = auVar1[3];
        auStack_1c[2] = (byte)rsp.routing_table_list;
        rsp._0_4_ = calloc(__nmemb,6);
        if ((void *)rsp._0_4_ == (void *)0x0) {
          if (__nmemb != 0) {
            auStack_1c[0] = 0x8a;
            goto _L0;
          }
          puVar7 = (undefined2 *)0x0;
          bVar2 = 0;
        }
        else {
          puVar7 = (undefined2 *)0x0;
          bVar2 = 0;
        }
        while ((puVar7 = (undefined2 *)nwk_route_table_next(puVar7), puVar7 != (undefined2 *)0x0 &&
               (auStack_1c[3] < __nmemb))) {
          if ((byte)rsp.routing_table_list <= bVar2) {
            *(undefined2 *)((uint)auStack_1c[3] * 6 + rsp._0_4_) = *puVar7;
            iVar6 = rsp._0_4_ + (uint)auStack_1c[3] * 6;
            *(byte *)(iVar6 + 2) = *(byte *)(iVar6 + 2) & 0xf8 | (byte)puVar7[7] & 7;
            iVar6 = rsp._0_4_ + (uint)auStack_1c[3] * 6;
            *(byte *)(iVar6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x13 & 1) << 3) | *(byte *)(iVar6 + 2) & 0xf7;
            iVar6 = rsp._0_4_ + (uint)auStack_1c[3] * 6;
            *(byte *)(iVar6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x14 & 1) << 4) | *(byte *)(iVar6 + 2) & 0xef;
            iVar6 = rsp._0_4_ + (uint)auStack_1c[3] * 6;
            *(byte *)(iVar6 + 2) =
                 (byte)((*(uint *)(puVar7 + 6) >> 0x15 & 1) << 5) | *(byte *)(iVar6 + 2) & 0xdf;
            *(undefined2 *)((uint)auStack_1c[3] * 6 + rsp._0_4_ + 4) = puVar7[1];
            auStack_1c[3] = auStack_1c[3] + 1;
          }
          bVar2 = bVar2 + 1;
        }
      }
    }
  }
  else {
    auStack_1c[0] = 0x84;
    auStack_1c[1] = '\0';
    auStack_1c[2] = '\0';
    auStack_1c[3] = '\0';
  }
_L0:
  zVar4 = auStack_1c[0];
  if (auStack_1c[0] != 0xfe) {
    zVar4 = zdo_op_nwk_mgmt_rtg_rsp(resp->payload,(zdp_nwk_mgmt_rtg_rsp_field_t *)auStack_1c,true);
  }
  auStack_1c[0] = zVar4;
  if (rsp._0_4_ != 0) {
    mm_free();
  }
  return auStack_1c[0];
}

