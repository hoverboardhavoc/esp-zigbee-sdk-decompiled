/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  ushort auStack_22 [3];
  
  if (param_1 == 3) {
    iVar3 = touchlink_commissioning_get();
    if (*(char *)(iVar3 + 1) == '\x02') {
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
      pcVar4 = (char *)touchlink_commissioning_get();
      if (*pcVar4 == '\x04') {
        iVar3 = touchlink_transaction_get();
        iVar5 = core_globals_get();
        if (*(int *)(iVar5 + 0xc) == 0 && *(int *)(iVar5 + 0x10) == 0) {
          puVar6 = (undefined4 *)nwk_get_extended_address();
          uVar7 = *puVar6;
          uVar1 = *(undefined3 *)(puVar6 + 1);
          uVar2 = *(undefined1 *)((int)puVar6 + 7);
        }
        else {
          iVar5 = core_globals_get();
          uVar7 = *(undefined4 *)(iVar5 + 0xc);
          uVar1 = *(undefined3 *)(iVar5 + 0x10);
          uVar2 = *(undefined1 *)(iVar5 + 0x13);
        }
        *(char *)(iVar3 + 0x611) = (char)uVar7;
        *(char *)(iVar3 + 0x612) = (char)((uint)uVar7 >> 8);
        *(char *)(iVar3 + 0x614) = (char)((uint)uVar7 >> 0x18);
        *(char *)(iVar3 + 0x615) = (char)uVar1;
        *(char *)(iVar3 + 0x616) = (char)((uint3)uVar1 >> 8);
        *(undefined1 *)(iVar3 + 0x618) = uVar2;
        *(char *)(iVar3 + 0x613) = (char)((uint)uVar7 >> 0x10);
        *(char *)(iVar3 + 0x617) = (char)((uint3)uVar1 >> 0x10);
        if (*(char *)(iVar3 + 0x61c) == '\0') {
          uVar2 = touchlink_assign_random_channel();
          *(undefined1 *)(iVar3 + 0x61c) = uVar2;
        }
        uVar8 = (uint)*(ushort *)(iVar3 + 0x61a);
        do {
          if ((uVar8 - 1 & 0xffff) < 0xfffe) {
            auStack_22[0] = 0;
            iVar5 = 0;
            do {
              iVar5 = nwk_disc_table_next(iVar5);
              if (iVar5 == 0) {
                *(short *)(iVar3 + 0x61a) = (short)uVar8;
                touchlink_send_network_start_rsp(iVar3 + 0x610);
                return;
              }
              nwk_address_get_panid(*(undefined1 *)(iVar5 + 8),auStack_22);
            } while (auStack_22[0] != uVar8);
          }
          uVar8 = random_noncrypto_get_u32();
          uVar8 = uVar8 % 0xffff;
        } while( true );
      }
      if (*pcVar4 == '\x06') {
        iVar5 = touchlink_transaction_get();
        nwk_set_extended_panid(iVar5 + 0x611);
        nwk_set_panid(*(undefined2 *)(iVar5 + 0x61a));
        nwk_set_short_address(*(undefined2 *)(iVar5 + 0x61e));
        iVar3 = touchlink_commissioning_get();
        if (*(char *)(iVar3 + 1) == '\x02') {
          nwk_secur_set_key(iVar5 + 0x620,0);
        }
        nwk_secur_switch_key(0);
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) & 0xfe;
        return;
      }
    }
  }
  else {
    if (param_1 < 4) {
      if (param_1 == 1) {
        iVar3 = touchlink_commissioning_get();
        if (*(char *)(iVar3 + 1) == '\x02') {
          if (param_2 == 0) {
            iVar3 = touchlink_transaction_get();
            nwk_secur_set_key(iVar3 + 0x620,0);
            nwk_secur_switch_key(0);
            uVar7 = 0x80;
            goto _L0;
          }
          goto _L0;
        }
      }
      else {
        if (param_1 != 2) {
          return;
        }
        iVar3 = touchlink_commissioning_get();
        if (*(char *)(iVar3 + 1) == '\x02') goto _L0;
      }
      goto _L0;
    }
    if (param_1 == 7) {
      iVar3 = touchlink_commissioning_get();
      if (*(char *)(iVar3 + 1) != '\x02') goto _L0;
      if (param_2 == 0) {
        uVar7 = 0x100;
_L0:
        zdo_initiate_commissioning(uVar7);
        return;
      }
    }
    else {
      if (param_1 != 8) {
        return;
      }
      iVar3 = touchlink_commissioning_get();
      if (*(char *)(iVar3 + 1) != '\x02') goto _L0;
      if (param_2 == 0) {
        uVar7 = 0;
        goto _L0;
      }
    }
  }
_L0:
  uVar7 = 1;
_L0:
  touchlink_commissioning_task_result(uVar7);
  return;
}

