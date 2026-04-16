/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_device_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_device_info_rsp_handler(touchlink_device_info_rsp_t *rsp)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  uint32_t uVar5;
  uint32_t *puVar6;
  int iVar7;
  int iVar8;
  ezb_err_t eVar9;
  uint uVar10;
  uint uVar11;
  zcl_touchlink_sub_device_info_record_t *pzVar12;
  undefined1 *puVar13;
  
  if (rsp == (touchlink_device_info_rsp_t *)0x0) {
    eVar9 = 2;
  }
  else {
    uVar5 = rsp->transaction_id;
    if ((uVar5 == 0) || (puVar6 = (uint32_t *)touchlink_transaction_get(), uVar5 != *puVar6)) {
      eVar9 = 3;
    }
    else if (rsp->start_index < 9) {
      iVar7 = touchlink_disc_table_find(&(rsp->cmd_ctrl).peer_addr.u);
      if (iVar7 == 0) {
        eVar9 = 5;
      }
      else {
        uVar10 = (uint)rsp->start_index;
        while( true ) {
          if (((int)(uint)rsp->n_records <= (int)(uVar10 - rsp->start_index)) || (7 < uVar10))
          break;
          uVar11 = uVar10 - rsp->start_index & 0xff;
          puVar13 = (undefined1 *)(uVar10 * 0x12 + iVar7 + 0x2a);
          pzVar12 = rsp->records + uVar11;
          uVar2 = *(undefined4 *)&(pzVar12->ieee_addr).field_0;
          puVar1 = (undefined4 *)((int)&(pzVar12->ieee_addr).field_0 + 4);
          uVar3 = *(undefined3 *)puVar1;
          uVar4 = *puVar1;
          *puVar13 = (char)*(undefined3 *)&(pzVar12->ieee_addr).field_0;
          puVar13[1] = (char)((uint)uVar2 >> 8);
          puVar13[2] = (char)((uint)uVar2 >> 0x10);
          puVar13[3] = (char)((uint)uVar2 >> 0x18);
          puVar13[4] = (char)uVar3;
          puVar13[5] = (char)((uint)uVar4 >> 8);
          puVar13[6] = (char)((uint)uVar4 >> 0x10);
          puVar13[7] = (char)((uint)uVar4 >> 0x18);
          puVar13[8] = rsp->records[uVar11].ep_id;
          *(uint16_t *)(puVar13 + 10) = rsp->records[uVar11].profile_id;
          *(uint16_t *)(puVar13 + 0xc) = rsp->records[uVar11].device_id;
          puVar13[0xe] = rsp->records[uVar11].version;
          puVar13[0xf] = rsp->records[uVar11].n_group_ids;
          *(char *)(iVar7 + 0x28) = *(char *)(iVar7 + 0x28) + '\x01';
          uVar10 = uVar10 + 1 & 0xff;
        }
        touchlink_print_disc_device();
        if (rsp->n_records == 0) {
          eVar9 = 0;
        }
        else if ((uint)rsp->n_records + (uint)rsp->start_index < 8) {
          iVar8 = touchlink_transaction_get();
          *(undefined1 *)(iVar8 + 0x60c) = 2;
          iVar8 = touchlink_transaction_get();
          *(int *)(iVar8 + 0x610) = iVar7;
          iVar7 = touchlink_transaction_get();
          touchlink_schedule_transaction_event(iVar7 + 0x60c);
          eVar9 = 0;
        }
        else {
          eVar9 = 0;
        }
      }
    }
    else {
      eVar9 = 2;
    }
  }
  return eVar9;
}

