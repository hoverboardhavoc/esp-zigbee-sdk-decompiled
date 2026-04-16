/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_nwk_addr_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001154c) */
/* WARNING: Removing unreachable block (ram,0x00011552) */
/* WARNING: Removing unreachable block (ram,0x0001177a) */
/* WARNING: Removing unreachable block (ram,0x0001155e) */
/* WARNING: Removing unreachable block (ram,0x0001165a) */
/* WARNING: Removing unreachable block (ram,0x0001167a) */
/* WARNING: Removing unreachable block (ram,0x0001171e) */
/* WARNING: Removing unreachable block (ram,0x0001170e) */
/* WARNING: Removing unreachable block (ram,0x00011734) */
/* WARNING: Removing unreachable block (ram,0x00011742) */
/* WARNING: Removing unreachable block (ram,0x0001174a) */
/* WARNING: Removing unreachable block (ram,0x00011752) */
/* WARNING: Removing unreachable block (ram,0x0001175c) */
/* WARNING: Removing unreachable block (ram,0x0001172e) */
/* WARNING: Removing unreachable block (ram,0x00011664) */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_addr_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  zdp_status_t zVar1;
  undefined3 extraout_var;
  int *piVar2;
  undefined2 *puVar3;
  byte bVar4;
  undefined1 local_40 [4];
  zdp_nwk_addr_rsp_field_t rsp;
  zdp_nwk_addr_req_field_t req;
  
  rsp.nwk_addr_assoc_dev_list = (ezb_shortaddr_t *)0x0;
  local_40 = (undefined1  [4])0x0;
  rsp._0_4_ = 0;
  rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
  rsp._8_4_ = 0;
  rsp.num_assoc_dev = '\0';
  rsp.start_index = '\0';
  rsp._14_2_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_nwk_addr_req(packet->payload,
                                (zdp_nwk_addr_req_field_t *)&rsp.nwk_addr_assoc_dev_list,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      local_40[1] = (char)rsp.nwk_addr_assoc_dev_list;
      local_40[2] = (char)((uint)rsp.nwk_addr_assoc_dev_list >> 8);
      local_40[3] = (char)((uint)rsp.nwk_addr_assoc_dev_list >> 0x10);
      rsp._0_4_ = (uint)rsp.nwk_addr_assoc_dev_list >> 0x18;
      rsp.ieee_addr_remote_dev.field_0.u64._3_2_ =
           (ushort)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xff00;
      rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
      piVar2 = (int *)nwk_get_extended_address();
      if (((ezb_shortaddr_t *)*piVar2 == rsp.nwk_addr_assoc_dev_list) && (piVar2[1] == 0)) {
        nwk_address_short_by_extended
                  (&rsp.nwk_addr_assoc_dev_list,
                   (undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
      }
      else {
        puVar3 = (undefined2 *)nwk_neighbor_table_get_by_extended(&rsp.nwk_addr_assoc_dev_list);
        if ((puVar3 != (undefined2 *)0x0) && ((*(uint *)(puVar3 + 6) & 3) == 2)) {
          nwk_address_short_by_ref
                    (*puVar3,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
        }
      }
      bVar4 = (byte)((uint)rsp.nwk_addr_assoc_dev_list >> 0x18);
      if ((uint)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ >> 0x10 == 0xffff) {
        if (packet->dst_addr < 0xfff8) {
          local_40[1] = (char)rsp.nwk_addr_assoc_dev_list;
          local_40[0] = 0x81;
          local_40[2] = (char)((uint)rsp.nwk_addr_assoc_dev_list >> 8);
          local_40[3] = (char)((uint)rsp.nwk_addr_assoc_dev_list >> 0x10);
          rsp.ieee_addr_remote_dev.field_0.u64._0_3_ = 0;
          rsp.status = bVar4;
          rsp.ieee_addr_remote_dev.field_0.u64._3_2_ =
               (short)((uint)rsp.ieee_addr_remote_dev.field_0._3_4_ >> 8) << 8;
          rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
          zVar1 = zdo_op_nwk_addr_rsp(resp->payload,'\0',(zdp_nwk_addr_rsp_field_t *)local_40,true);
        }
        else {
          zVar1 = 0xfe;
        }
      }
      else {
        local_40 = (undefined1  [4])((int)rsp.nwk_addr_assoc_dev_list << 8);
        rsp.ieee_addr_remote_dev.field_0.u64._0_3_ = 0;
        rsp.status = bVar4;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ =
             rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffffff00;
        nwk_address_short_by_extended
                  (local_40 + 1,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
        zVar1 = zdo_op_nwk_addr_rsp(resp->payload,'\0',(zdp_nwk_addr_rsp_field_t *)local_40,true);
      }
    }
    else {
      zVar1 = 0xfe;
    }
  }
  if (rsp._12_4_ != 0) {
    mm_free();
  }
  return zVar1;
}

