/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_device_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_device_info_rsp_handler(touchlink_device_info_rsp_t *rsp)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined3 uVar5;
  undefined4 uVar6;
  uint32_t uVar7;
  ezb_err_t eVar8;
  uint32_t *puVar9;
  int iVar10;
  zcl_touchlink_sub_device_info_record_t *pzVar11;
  undefined1 *puVar12;
  int iVar13;
  
  if (rsp == (touchlink_device_info_rsp_t *)0x0) {
    return 2;
  }
  uVar7 = rsp->transaction_id;
  if ((uVar7 == 0) || (puVar9 = (uint32_t *)touchlink_transaction_get(), uVar7 != *puVar9)) {
    eVar8 = 3;
  }
  else {
    eVar8 = 2;
    if (rsp->start_index < 9) {
      iVar10 = touchlink_disc_table_find(&(rsp->cmd_ctrl).peer_addr.u);
      eVar8 = 5;
      if (iVar10 != 0) {
        bVar2 = rsp->start_index;
        bVar3 = rsp->n_records;
        puVar12 = (undefined1 *)((uint)bVar2 * 0x12 + 0x2a + iVar10);
        for (iVar13 = 0; (iVar13 < (int)(uint)bVar3 && (((uint)bVar2 + iVar13 & 0xff) < 8));
            iVar13 = iVar13 + 1) {
          pzVar11 = rsp->records + iVar13;
          puVar1 = (undefined4 *)((int)&(pzVar11->ieee_addr).field_0 + 4);
          uVar4 = *(undefined4 *)&(pzVar11->ieee_addr).field_0;
          uVar5 = *(undefined3 *)puVar1;
          uVar6 = *puVar1;
          *puVar12 = (char)*(undefined3 *)&(pzVar11->ieee_addr).field_0;
          puVar12[1] = (char)((uint)uVar4 >> 8);
          puVar12[3] = (char)((uint)uVar4 >> 0x18);
          puVar12[5] = (char)((uint)uVar6 >> 8);
          puVar12[2] = (char)((uint)uVar4 >> 0x10);
          puVar12[4] = (char)uVar5;
          puVar12[6] = (char)((uint)uVar6 >> 0x10);
          puVar12[7] = (char)((uint)uVar6 >> 0x18);
          puVar12[8] = pzVar11->ep_id;
          *(uint16_t *)(puVar12 + 10) = pzVar11->profile_id;
          *(uint16_t *)(puVar12 + 0xc) = pzVar11->device_id;
          puVar12[0xe] = pzVar11->version;
          puVar12[0xf] = pzVar11->n_group_ids;
          *(char *)(iVar10 + 0x28) = *(char *)(iVar10 + 0x28) + '\x01';
          puVar12 = puVar12 + 0x12;
        }
        touchlink_print_disc_device();
        if ((rsp->n_records != 0) && ((uint)rsp->start_index + (uint)rsp->n_records < 8)) {
          iVar13 = touchlink_transaction_get();
          *(undefined1 *)(iVar13 + 0x60c) = 2;
          iVar13 = touchlink_transaction_get();
          *(int *)(iVar13 + 0x610) = iVar10;
          iVar10 = touchlink_transaction_get();
          touchlink_schedule_transaction_event(iVar10 + 0x60c);
        }
        eVar8 = 0;
      }
    }
  }
  return eVar8;
}

