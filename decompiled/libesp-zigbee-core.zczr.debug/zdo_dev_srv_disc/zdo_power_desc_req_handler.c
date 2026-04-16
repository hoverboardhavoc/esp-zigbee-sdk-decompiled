/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_power_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_power_desc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  uint uVar1;
  zdp_status_t zVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint16_t uStack_1e;
  undefined1 auStack_1c [2];
  uint16_t short_addr;
  zdp_power_desc_rsp_field_t rsp;
  zdp_power_desc_req_field_t req;
  
  rsp.power_desc.u16 = 0;
  auStack_1c[0] = '\0';
  auStack_1c[1] = 0;
  short_addr = 0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    zVar2 = zdo_op_power_desc_req
                      (packet->payload,(zdp_power_desc_req_field_t *)&rsp.power_desc.field_0,false);
    if (CONCAT31(extraout_var,zVar2) == 0) {
      uVar1 = (uint)rsp.power_desc.u16;
      if (uVar1 < 0xfff8) {
        _auStack_1c = CONCAT22(rsp.power_desc.u16,auStack_1c);
        uVar3 = nwk_get_short_address();
        if (uVar1 == uVar3) {
          _auStack_1c = _auStack_1c & 0xffffff00;
        }
        else {
          iVar4 = nwk_is_device_zed();
          if (iVar4 == 0) {
            _auStack_1c = CONCAT31(stack0xffffffe5,0x81);
            puVar5 = (undefined2 *)0x0;
            do {
              do {
                puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
                if (puVar5 == (undefined2 *)0x0) goto _L0;
              } while ((*(uint *)(puVar5 + 6) & 3) != 2);
              uStack_1e = 0xffff;
              nwk_address_short_by_ref(*puVar5,&uStack_1e);
            } while (rsp.power_desc.u16 != uStack_1e);
          }
          else {
            _auStack_1c = CONCAT31(stack0xffffffe5,0x80);
          }
        }
_L0:
        rsp.status = '\0';
        rsp._1_1_ = 0;
        if (((_auStack_1c & 0xff) == 0) &&
           (puVar5 = (undefined2 *)af_get_node_power_desc(), puVar5 != (undefined2 *)0x0)) {
          rsp._0_2_ = *puVar5;
        }
        zVar2 = zdo_op_power_desc_rsp(resp->payload,(zdp_power_desc_rsp_field_t *)auStack_1c,true);
      }
      else {
        zVar2 = 0x8b;
      }
    }
    else {
      zVar2 = 0xfe;
    }
  }
  return zVar2;
}

