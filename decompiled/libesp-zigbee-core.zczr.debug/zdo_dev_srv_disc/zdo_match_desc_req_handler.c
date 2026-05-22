/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_match_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000120c6) */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_match_desc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  uint uVar1;
  undefined2 *puVar2;
  zdp_status_t zVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  ushort uStack_2a;
  undefined1 auStack_28 [2];
  uint16_t short_addr;
  zdp_match_desc_rsp_field_t rsp;
  zdp_match_desc_req_field_t req;
  
  rsp.match_list = (uint8_t *)0x0;
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  short_addr = 0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.match_length = '\0';
  rsp._5_3_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar3 = 0xfe;
  }
  else {
    zVar3 = zdo_op_match_desc_req
                      (packet->payload,(zdp_match_desc_req_field_t *)&rsp.match_list,false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      iVar4 = nwk_is_device_zed();
      if (iVar4 == 0) {
        uVar1 = (uint)rsp.match_list & 0xffff;
        uVar5 = nwk_get_short_address();
        if ((uVar1 == uVar5) || (0xfff7 < ((uint)rsp.match_list & 0xffff))) {
          auStack_28[0] = '\0';
        }
        else {
          uStack_2a = 0xffff;
          auStack_28[0] = 0x81;
          puVar2 = (undefined2 *)0x0;
          do {
            do {
              puVar2 = (undefined2 *)nwk_neighbor_table_next(puVar2);
              if (puVar2 == (undefined2 *)0x0) goto _L0;
            } while ((*(uint *)(puVar2 + 6) & 3) != 2);
            nwk_address_short_by_ref(*puVar2,&uStack_2a);
          } while (((uint)rsp.match_list & 0xffff) != (uint)uStack_2a);
          auStack_28[0] = '\0';
        }
      }
      else {
        uVar1 = (uint)rsp.match_list & 0xffff;
        uVar5 = nwk_get_short_address();
        if ((uVar1 == uVar5) || (0xfff7 < (ushort)rsp.match_list)) {
          auStack_28[0] = '\0';
        }
        else {
          auStack_28[0] = 0x80;
        }
      }
_L0:
      zVar3 = setup_match_desc_response
                        (resp->payload,(zdp_match_desc_rsp_field_t *)auStack_28,
                         (zdp_match_desc_req_field_t *)&rsp.match_list);
    }
    else {
      zVar3 = 0xfe;
    }
  }
  return zVar3;
}

