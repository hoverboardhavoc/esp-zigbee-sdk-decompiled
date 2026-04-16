/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_scan_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_scan_rsp_handler(touchlink_scan_rsp_t *rsp)

{
  ezb_addr_t *peVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ezb_grpaddr_t eVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint32_t uVar8;
  undefined1 uVar9;
  ushort uVar10;
  uint32_t *puVar11;
  ezb_err_t eVar12;
  int iVar13;
  
  if (rsp == (touchlink_scan_rsp_t *)0x0) {
    eVar12 = 2;
  }
  else {
    uVar8 = rsp->transaction_id;
    if ((uVar8 == 0) || (puVar11 = (uint32_t *)touchlink_transaction_get(), uVar8 != *puVar11)) {
      eVar12 = 3;
    }
    else {
      uVar3 = rsp->key_bitmask;
      uVar10 = touchlink_get_key_bitmask();
      if ((uVar3 & uVar10) == 0) {
        eVar12 = 2;
      }
      else {
        iVar13 = touchlink_disc_table_find(&(rsp->cmd_ctrl).peer_addr.u);
        if (iVar13 == 0) {
          puVar11 = (uint32_t *)touchlink_disc_table_get_entry();
          if (puVar11 == (uint32_t *)0x0) {
            eVar12 = 1;
          }
          else {
            peVar1 = &(rsp->cmd_ctrl).peer_addr.u;
            eVar4 = peVar1->group_addr;
            puVar2 = (undefined4 *)((int)&(rsp->cmd_ctrl).peer_addr.u + 4);
            uVar5 = *(undefined2 *)puVar2;
            uVar6 = *puVar2;
            *(char *)((int)puVar11 + 0xf) = (char)(peVar1->group_addr).group;
            *(char *)(puVar11 + 4) = eVar4.group._1_1_;
            *(char *)((int)puVar11 + 0x11) = eVar4.bcast;
            *(char *)((int)puVar11 + 0x12) = eVar4.bcast._1_1_;
            *(char *)((int)puVar11 + 0x13) = (char)uVar5;
            *(char *)(puVar11 + 5) = (char)((uint)uVar6 >> 8);
            *(char *)((int)puVar11 + 0x15) = (char)((uint)uVar6 >> 0x10);
            *(char *)((int)puVar11 + 0x16) = (char)((uint)uVar6 >> 0x18);
            uVar6 = *(undefined4 *)&(rsp->ext_panid).field_0;
            puVar2 = (undefined4 *)((int)&(rsp->ext_panid).field_0 + 4);
            uVar5 = *(undefined2 *)puVar2;
            uVar7 = *puVar2;
            *(char *)((int)puVar11 + 0x17) = (char)*(undefined2 *)&(rsp->ext_panid).field_0;
            *(char *)(puVar11 + 6) = (char)((uint)uVar6 >> 8);
            *(char *)((int)puVar11 + 0x19) = (char)((uint)uVar6 >> 0x10);
            *(char *)((int)puVar11 + 0x1a) = (char)((uint)uVar6 >> 0x18);
            *(char *)((int)puVar11 + 0x1b) = (char)uVar5;
            *(char *)(puVar11 + 7) = (char)((uint)uVar7 >> 8);
            *(char *)((int)puVar11 + 0x1d) = (char)((uint)uVar7 >> 0x10);
            *(char *)((int)puVar11 + 0x1e) = (char)((uint)uVar7 >> 0x18);
            *puVar11 = rsp->transaction_id;
            *(ushort *)(puVar11 + 2) = (ushort)rsp->zigbee_info;
            *(uint8_t *)((int)puVar11 + 10) = rsp->touchlink_info;
            *(uint16_t *)(puVar11 + 3) = rsp->key_bitmask;
            *(uint8_t *)((int)puVar11 + 0xe) = rsp->rssi_correction;
            puVar11[1] = rsp->response_id;
            *(uint8_t *)((int)puVar11 + 0x1f) = rsp->nwk_update_id;
            *(uint8_t *)(puVar11 + 8) = rsp->channel;
            uVar9 = touchlink_get_intrp_channel();
            *(undefined1 *)((int)puVar11 + 0x21) = uVar9;
            *(ezb_panid_t *)((int)puVar11 + 0x22) = rsp->pan_id;
            *(ezb_shortaddr_t *)(puVar11 + 9) = rsp->nwk_addr;
            *(uint8_t *)((int)puVar11 + 0x26) = rsp->n_subdevs;
            *(uint8_t *)((int)puVar11 + 0x27) = rsp->total_group_ids;
            *(int8_t *)(puVar11 + 0x2f) = (rsp->cmd_ctrl).rssi;
            if ((rsp->n_subdevs == '\x01') && ((char)puVar11[10] == '\0')) {
              peVar1 = &(rsp->cmd_ctrl).peer_addr.u;
              eVar4 = peVar1->group_addr;
              puVar2 = (undefined4 *)((int)&(rsp->cmd_ctrl).peer_addr.u + 4);
              uVar5 = *(undefined2 *)puVar2;
              uVar6 = *puVar2;
              *(ezb_shortaddr_t *)((int)puVar11 + 0x2a) = (peVar1->group_addr).group;
              *(ezb_shortaddr_t *)(puVar11 + 0xb) = eVar4.bcast;
              *(undefined2 *)((int)puVar11 + 0x2e) = uVar5;
              *(short *)(puVar11 + 0xc) = (short)((uint)uVar6 >> 0x10);
              *(uint8_t *)((int)puVar11 + 0x32) = (rsp->sub_device).ep_id;
              *(uint16_t *)(puVar11 + 0xd) = (rsp->sub_device).profile_id;
              *(uint16_t *)((int)puVar11 + 0x36) = (rsp->sub_device).device_id;
              *(uint8_t *)(puVar11 + 0xe) = (rsp->sub_device).version;
              *(uint8_t *)((int)puVar11 + 0x39) = (rsp->sub_device).n_group_ids;
              *(undefined1 *)(puVar11 + 10) = 1;
            }
            touchlink_print_disc_device();
            eVar12 = 0;
          }
        }
        else {
          eVar12 = 3;
        }
      }
    }
  }
  return eVar12;
}

