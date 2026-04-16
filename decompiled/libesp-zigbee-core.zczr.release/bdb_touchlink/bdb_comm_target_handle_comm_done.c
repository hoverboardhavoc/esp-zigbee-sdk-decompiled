/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> bdb_comm_target_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_target_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  undefined3 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined3 in_register_00002029;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  ushort auStack_22 [2];
  ezb_panid_t parent_pan_id;
  
  uVar4 = CONCAT31(in_register_00002029,op);
  if (uVar4 == 3) {
    iVar5 = touchlink_commissioning_get();
    if (*(char *)(iVar5 + 1) == '\x02') {
      if (error == 0) {
        return;
      }
      goto _L0;
    }
_L0:
    while( true ) {
      __assert_func(0,0,0,0);
_L0:
      if (error != 0) break;
      pcVar6 = (char *)touchlink_commissioning_get();
      if (*pcVar6 == '\x04') {
        iVar5 = touchlink_transaction_get();
        iVar7 = core_globals_get();
        if (*(int *)(iVar7 + 0xc) == 0 && *(int *)(iVar7 + 0x10) == 0) {
          puVar8 = (undefined4 *)nwk_get_extended_address();
          uVar9 = *puVar8;
          uVar1 = *(undefined3 *)(puVar8 + 1);
          uVar2 = *(undefined1 *)((int)puVar8 + 7);
        }
        else {
          iVar7 = core_globals_get();
          uVar9 = *(undefined4 *)(iVar7 + 0xc);
          uVar1 = *(undefined3 *)(iVar7 + 0x10);
          uVar2 = *(undefined1 *)(iVar7 + 0x13);
        }
        *(char *)(iVar5 + 0x611) = (char)uVar9;
        *(char *)(iVar5 + 0x612) = (char)((uint)uVar9 >> 8);
        *(char *)(iVar5 + 0x614) = (char)((uint)uVar9 >> 0x18);
        *(char *)(iVar5 + 0x615) = (char)uVar1;
        *(char *)(iVar5 + 0x616) = (char)((uint3)uVar1 >> 8);
        *(undefined1 *)(iVar5 + 0x618) = uVar2;
        *(char *)(iVar5 + 0x613) = (char)((uint)uVar9 >> 0x10);
        *(char *)(iVar5 + 0x617) = (char)((uint3)uVar1 >> 0x10);
        if (*(char *)(iVar5 + 0x61c) == '\0') {
          uVar2 = touchlink_assign_random_channel();
          *(undefined1 *)(iVar5 + 0x61c) = uVar2;
        }
        uVar3 = *(ushort *)(iVar5 + 0x61a);
        iVar7 = 0;
        while (iVar7 = nwk_disc_table_next(iVar7), iVar7 != 0) {
          nwk_address_get_panid(*(undefined1 *)(iVar7 + 8),auStack_22);
          if ((auStack_22[0] == uVar3) || (0xfffd < (ushort)(uVar3 - 1))) {
            uVar3 = random_noncrypto_get_u32();
            iVar7 = 0;
          }
        }
        *(ushort *)(iVar5 + 0x61a) = uVar3;
        touchlink_send_network_start_rsp(iVar5 + 0x610);
        return;
      }
      if (*pcVar6 == '\x06') {
        iVar7 = touchlink_transaction_get();
        nwk_set_extended_panid(iVar7 + 0x611);
        nwk_set_panid(*(undefined2 *)(iVar7 + 0x61a));
        nwk_set_short_address(*(undefined2 *)(iVar7 + 0x61e));
        iVar5 = touchlink_commissioning_get();
        if (*(char *)(iVar5 + 1) == '\x02') {
          nwk_secur_set_key(iVar7 + 0x620,0);
        }
        nwk_secur_switch_key(0);
        iVar5 = core_globals_get();
        *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) & 0xfe;
        return;
      }
    }
  }
  else {
    if (uVar4 < 4) {
      if (uVar4 == 1) {
        iVar5 = touchlink_commissioning_get();
        if (*(char *)(iVar5 + 1) == '\x02') {
          if (error == 0) {
            iVar5 = touchlink_transaction_get();
            nwk_secur_set_key(iVar5 + 0x620,0);
            nwk_secur_switch_key(0);
            uVar9 = 0x80;
            goto _L0;
          }
          goto _L0;
        }
      }
      else {
        if (uVar4 != 2) {
          return;
        }
        iVar5 = touchlink_commissioning_get();
        if (*(char *)(iVar5 + 1) == '\x02') goto _L0;
      }
      goto _L0;
    }
    if (uVar4 == 7) {
      iVar5 = touchlink_commissioning_get();
      if (*(char *)(iVar5 + 1) != '\x02') goto _L0;
      if (error == 0) {
        uVar9 = 0x100;
_L0:
        zdo_initiate_commissioning(uVar9);
        return;
      }
    }
    else {
      if (uVar4 != 8) {
        return;
      }
      iVar5 = touchlink_commissioning_get();
      if (*(char *)(iVar5 + 1) != '\x02') goto _L0;
      if (error == 0) {
        uVar9 = 0;
        goto _L0;
      }
    }
  }
_L0:
  uVar9 = 1;
_L0:
  touchlink_commissioning_task_result(uVar9);
  return;
}

