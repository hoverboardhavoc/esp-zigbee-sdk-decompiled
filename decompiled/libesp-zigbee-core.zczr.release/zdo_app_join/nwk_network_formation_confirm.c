/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> nwk_network_formation_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_network_formation_confirm(uint param_1,uint param_2,char *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 uStack_1d;
  uint uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  if (param_1 == 0) {
    uVar4 = nwk_secur_get_current_key_seq();
    iVar5 = nwk_secur_get_key_by_seq();
    if (iVar5 == 0) goto _L0;
    param_3 = (char *)(iVar5 + 0xf);
    param_2 = 0x10;
_L0:
    param_2 = param_2 - 1 & 0xff;
    if (*param_3 == '\0') goto _L0;
    if (param_2 == 0) goto _L0;
    do {
      iVar5 = nwk_secur_switch_key(uVar4);
      if (iVar5 == 0) {
        iVar5 = core_globals_get();
        if (*(short *)(iVar5 + 0xcc2) != 0) {
          iVar5 = core_globals_get();
          uVar2 = __ctzsi2(*(undefined2 *)(iVar5 + 0xcc2));
          if (uVar2 != 0) {
            iVar5 = core_globals_get();
            *(ushort *)(iVar5 + 0xcc2) = ~(ushort)(1 << (uVar2 & 0x1f)) & *(ushort *)(iVar5 + 0xcc2)
            ;
            iVar5 = core_globals_get();
            *(char *)(iVar5 + 0xcc0) = (char)uVar2;
            if (uVar2 == 6) {
              param_1 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
            }
            else if ((int)uVar2 < 7) {
              if (uVar2 == 2) {
                iVar5 = core_globals_get();
                uStack_1c = *(uint *)(iVar5 + 8);
                uStack_1d = 3;
                iVar5 = core_globals_get();
                uVar2 = *(uint *)(iVar5 + 0xcdc);
                uVar4 = nwk_is_device_zed();
                zdo_comm_get_scan_duration_isra_0(&uStack_1d);
                zdo_comm_get_channel_mask_isra_0(&uStack_1c);
                iVar5 = core_globals_get();
                uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar5 + 8) & uStack_1c & 0x7ffffff;
                param_1 = nwk_network_discovery(uStack_1d,uVar2 & 1 ^ 1,uVar4);
              }
              else if ((int)uVar2 < 3) {
                uStack_1c = 0;
                uStack_18 = 0;
                iVar5 = core_globals_get();
                uStack_1c = *(uint *)(iVar5 + 8);
                uStack_18 = CONCAT31(uStack_18._1_3_,3);
                iVar5 = aps_secur_is_centralized();
                if (iVar5 == 0) {
                  uStack_18 = uStack_18 | 0x2000000;
                }
                else {
                  uStack_18 = uStack_18 & 0xfdffffff;
                  iVar5 = nwk_is_device_zc();
                  if (iVar5 != 0) {
                    nwk_get_extended_address();
                    aps_secur_set_tc_address();
                  }
                }
                zdo_comm_get_scan_duration_isra_0(&uStack_18);
                zdo_comm_get_channel_mask_isra_0(&uStack_1c);
                iVar5 = core_globals_get();
                uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar5 + 8) & uStack_1c & 0x7ffffff;
                param_1 = nwk_network_formation_request(&uStack_1c);
              }
              else {
                iVar5 = nwk_disc_table_next(0);
                if (iVar5 == 0) {
                  param_1 = 0x1ea;
                  goto zdo_comm_signal_comm_done;
                }
                uStack_1c = 0;
                uStack_18 = 0;
                uStack_14 = 0;
                bStack_12 = 0;
                iVar3 = af_get_node_desc();
                uStack_14._1_1_ = *(undefined1 *)(iVar3 + 2);
                nwk_address_get_extpanid(*(undefined1 *)(iVar5 + 8),&uStack_1c);
                iVar5 = core_globals_get();
                uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar5 + 0xcdc) & 1) << 1));
                iVar5 = core_globals_get();
                bStack_12 = bStack_12 & 0xfe | *(char *)(iVar5 + 0xcc0) == '\x03';
                param_1 = nwk_join_request(&uStack_1c);
              }
            }
            else {
              if (uVar2 == 8) {
                uStack_1c = 0;
                uStack_18 = 0;
                zdo_device_annce_req(&uStack_1c);
                zdo_comm_perform_next_op();
                return;
              }
              if (uVar2 != 9) {
                if (uVar2 != 7) {
                  __assert_func(0,0,0,0);
                  goto _L0;
                }
                ds_save_common_data();
                iVar5 = nwk_is_device_zczr();
                if (iVar5 != 0) {
                  uStack_1c = uStack_1c & 0xff000000;
                  param_1 = nwk_start_router(&uStack_1c);
                  if ((param_1 != 0) || (param_1 = nwk_permit_joining(), param_1 != 0))
                  goto zdo_comm_signal_comm_done;
                }
                iVar5 = nwk_is_device_zed();
                if ((iVar5 == 0) || (param_1 = nwk_start_end_device(), param_1 == 0)) {
                  iVar5 = core_globals_get();
                  tasklet_post(iVar5 + 0xcc4);
                  return;
                }
                goto zdo_comm_signal_comm_done;
              }
              param_1 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
            }
            if (param_1 == 0) {
              return;
            }
            goto zdo_comm_signal_comm_done;
          }
        }
_L0:
        param_1 = 0;
        goto zdo_comm_signal_comm_done;
      }
      __assert_func(0,0,0,0);
_L0:
      param_3 = param_3 + -1;
      if (param_2 != 0) goto _L0;
_L0:
      nwk_secur_set_key(0,0);
      uVar4 = 0;
    } while( true );
  }
  param_1 = param_1 | 0x200;
zdo_comm_signal_comm_done:
  iVar5 = core_globals_get();
  bVar1 = *(byte *)(iVar5 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar5 = core_globals_get();
  *(undefined2 *)(iVar5 + 0xcc2) = 0;
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (param_1 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (param_1 == 0) goto _L0;
    if (9 < uVar2) {
      uVar4 = zdo_comm_op_to_str_part_0();
      iVar5 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar5 + 0xcd4))(2,4,uVar4,*(code **)(iVar5 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),param_1);
_L0:
  iVar5 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = param_1;
  (**(code **)(iVar5 + 0xcd8))(3,&uStack_18,*(code **)(iVar5 + 0xcd8));
  return;
}

