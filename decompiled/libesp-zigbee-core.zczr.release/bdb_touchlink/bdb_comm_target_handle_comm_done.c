/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> bdb_comm_target_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_target_handle_comm_done(uint param_1,int param_2)

{
  undefined3 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  ushort auStack_22 [5];
  
  if (param_1 == 3) {
    iVar4 = touchlink_commissioning_get();
    if (*(char *)(iVar4 + 1) == '\x02') {
      if (param_2 == 0) {
        return;
      }
      goto _L0;
    }
_L0:
    while( true ) {
      __assert_func(0,0,0,0);
_L0:
      if (param_2 != 0) break;
      pcVar5 = (char *)touchlink_commissioning_get();
      if (*pcVar5 == '\x04') {
        iVar4 = touchlink_transaction_get();
        iVar6 = core_globals_get();
        if (*(int *)(iVar6 + 0xc) == 0 && *(int *)(iVar6 + 0x10) == 0) {
          puVar7 = (undefined4 *)nwk_get_extended_address();
          uVar8 = *puVar7;
          uVar1 = *(undefined3 *)(puVar7 + 1);
          uVar2 = *(undefined1 *)((int)puVar7 + 7);
        }
        else {
          iVar6 = core_globals_get();
          uVar8 = *(undefined4 *)(iVar6 + 0xc);
          uVar1 = *(undefined3 *)(iVar6 + 0x10);
          uVar2 = *(undefined1 *)(iVar6 + 0x13);
        }
        *(char *)(iVar4 + 0x611) = (char)uVar8;
        *(char *)(iVar4 + 0x612) = (char)((uint)uVar8 >> 8);
        *(char *)(iVar4 + 0x614) = (char)((uint)uVar8 >> 0x18);
        *(char *)(iVar4 + 0x615) = (char)uVar1;
        *(char *)(iVar4 + 0x616) = (char)((uint3)uVar1 >> 8);
        *(undefined1 *)(iVar4 + 0x618) = uVar2;
        *(char *)(iVar4 + 0x613) = (char)((uint)uVar8 >> 0x10);
        *(char *)(iVar4 + 0x617) = (char)((uint3)uVar1 >> 0x10);
        if (*(char *)(iVar4 + 0x61c) == '\0') {
          uVar2 = touchlink_assign_random_channel();
          *(undefined1 *)(iVar4 + 0x61c) = uVar2;
        }
        uVar3 = *(ushort *)(iVar4 + 0x61a);
        iVar6 = 0;
        while (iVar6 = nwk_disc_table_next(iVar6), iVar6 != 0) {
          nwk_address_get_panid(*(undefined1 *)(iVar6 + 8),auStack_22);
          if ((auStack_22[0] == uVar3) || (0xfffd < (ushort)(uVar3 - 1))) {
            uVar3 = random_noncrypto_get_u32();
            iVar6 = 0;
          }
        }
        *(ushort *)(iVar4 + 0x61a) = uVar3;
        touchlink_send_network_start_rsp(iVar4 + 0x610);
        return;
      }
      if (*pcVar5 == '\x06') {
        iVar6 = touchlink_transaction_get();
        nwk_set_extended_panid(iVar6 + 0x611);
        nwk_set_panid(*(undefined2 *)(iVar6 + 0x61a));
        nwk_set_short_address(*(undefined2 *)(iVar6 + 0x61e));
        iVar4 = touchlink_commissioning_get();
        if (*(char *)(iVar4 + 1) == '\x02') {
          nwk_secur_set_key(iVar6 + 0x620,0);
        }
        nwk_secur_switch_key(0);
        iVar4 = core_globals_get();
        *(byte *)(iVar4 + 0xb18) = *(byte *)(iVar4 + 0xb18) & 0xfe;
        return;
      }
    }
  }
  else {
    if (param_1 < 4) {
      if (param_1 == 1) {
        iVar4 = touchlink_commissioning_get();
        if (*(char *)(iVar4 + 1) == '\x02') {
          if (param_2 == 0) {
            iVar4 = touchlink_transaction_get();
            nwk_secur_set_key(iVar4 + 0x620,0);
            nwk_secur_switch_key(0);
            uVar8 = 0x80;
            goto _L0;
          }
          goto _L0;
        }
      }
      else {
        if (param_1 != 2) {
          return;
        }
        iVar4 = touchlink_commissioning_get();
        if (*(char *)(iVar4 + 1) == '\x02') goto _L0;
      }
      goto _L0;
    }
    if (param_1 == 7) {
      iVar4 = touchlink_commissioning_get();
      if (*(char *)(iVar4 + 1) != '\x02') goto _L0;
      if (param_2 == 0) {
        uVar8 = 0x100;
_L0:
        zdo_initiate_commissioning(uVar8);
        return;
      }
    }
    else {
      if (param_1 != 8) {
        return;
      }
      iVar4 = touchlink_commissioning_get();
      if (*(char *)(iVar4 + 1) != '\x02') goto _L0;
      if (param_2 == 0) {
        uVar8 = 0;
        goto _L0;
      }
    }
  }
_L0:
  uVar8 = 1;
_L0:
  touchlink_commissioning_task_result(uVar8);
  return;
}

