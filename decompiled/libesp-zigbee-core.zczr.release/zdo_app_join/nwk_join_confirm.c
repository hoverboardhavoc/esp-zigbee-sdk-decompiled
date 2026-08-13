/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> nwk_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_confirm(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 uStack_1d;
  uint uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  if (*param_1 != 0) {
    if ((param_1[1] == 0) || (param_1[1] == 3)) {
      iVar4 = core_globals_get();
      *(ushort *)(iVar4 + 0xcc2) = *(ushort *)(iVar4 + 0xcc2) | 0x20;
      goto _L0;
    }
    uVar5 = *param_1 | 0x200;
    goto zdo_comm_signal_comm_done;
  }
_L0:
  iVar4 = core_globals_get();
  if (*(short *)(iVar4 + 0xcc2) == 0) {
_L0:
    uVar5 = 0;
  }
  else {
    iVar4 = core_globals_get();
    uVar5 = __ctzsi2(*(undefined2 *)(iVar4 + 0xcc2));
    if (uVar5 == 0) goto _L0;
    iVar4 = core_globals_get();
    *(ushort *)(iVar4 + 0xcc2) = ~(ushort)(1 << (uVar5 & 0x1f)) & *(ushort *)(iVar4 + 0xcc2);
    iVar4 = core_globals_get();
    *(char *)(iVar4 + 0xcc0) = (char)uVar5;
    if (uVar5 == 6) {
      uVar5 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
_L0:
      if (uVar5 == 0) {
        return;
      }
    }
    else {
      if ((int)uVar5 < 7) {
        if (uVar5 == 2) {
          iVar4 = core_globals_get();
          uStack_1c = *(uint *)(iVar4 + 8);
          uStack_1d = 3;
          iVar4 = core_globals_get();
          uVar5 = *(uint *)(iVar4 + 0xcdc);
          iVar4 = core_globals_get();
          uVar6 = 0;
          if ((*(uint *)(iVar4 + 0xcdc) & 1) == 0) {
            uVar6 = nwk_is_device_zed();
          }
          zdo_comm_get_scan_duration_isra_0(&uStack_1d);
          zdo_comm_get_channel_mask_isra_0(&uStack_1c);
          iVar4 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar4 + 8) & uStack_1c & 0x7ffffff;
          uVar5 = nwk_network_discovery(uStack_1d,uVar5 & 1 ^ 1,uVar6);
        }
        else if ((int)uVar5 < 3) {
          uStack_1c = 0;
          uStack_18 = 0;
          iVar4 = core_globals_get();
          uStack_1c = *(uint *)(iVar4 + 8);
          uStack_18 = CONCAT31(uStack_18._1_3_,3);
          iVar4 = aps_secur_is_centralized();
          if (iVar4 == 0) {
            uStack_18 = uStack_18 | 0x2000000;
          }
          else {
            uStack_18 = uStack_18 & 0xfdffffff;
            iVar4 = nwk_is_device_zc();
            if (iVar4 != 0) {
              nwk_get_extended_address();
              aps_secur_set_tc_address();
            }
          }
          zdo_comm_get_scan_duration_isra_0(&uStack_18);
          zdo_comm_get_channel_mask_isra_0(&uStack_1c);
          iVar4 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar4 + 8) & uStack_1c & 0x7ffffff;
          uVar5 = nwk_network_formation_request(&uStack_1c);
        }
        else {
          iVar4 = nwk_disc_table_next(0);
          if (iVar4 == 0) {
            uVar5 = 0x1ea;
            goto zdo_comm_signal_comm_done;
          }
          uStack_1c = 0;
          uStack_18 = 0;
          uStack_14 = 0;
          bStack_12 = 0;
          iVar3 = af_get_node_desc();
          uStack_14._1_1_ = *(undefined1 *)(iVar3 + 2);
          nwk_address_get_extpanid(*(undefined1 *)(iVar4 + 8),&uStack_1c);
          iVar4 = core_globals_get();
          uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar4 + 0xcdc) & 1) << 1));
          iVar4 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar4 + 0xcc0) == '\x03';
          uVar5 = nwk_join_request(&uStack_1c);
        }
        goto _L0;
      }
      if (uVar5 == 8) {
        uStack_1c = 0;
        uStack_18 = 0;
        zdo_device_annce_req(&uStack_1c);
        zdo_comm_perform_next_op();
        return;
      }
      if (uVar5 == 9) {
        uVar5 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
        goto _L0;
      }
      if (uVar5 != 7) {
        __assert_func(0,0,0,0);
        goto _L0;
      }
      ds_save_common_data();
      iVar4 = nwk_is_device_zczr();
      if (iVar4 != 0) {
        uStack_1c = uStack_1c & 0xff000000;
        uVar5 = nwk_start_router(&uStack_1c);
        if ((uVar5 != 0) || (uVar5 = nwk_permit_joining(), uVar5 != 0))
        goto zdo_comm_signal_comm_done;
      }
      iVar4 = nwk_is_device_zed();
      if ((iVar4 == 0) || (uVar5 = nwk_start_end_device(), uVar5 == 0)) {
        iVar4 = core_globals_get();
        tasklet_post(iVar4 + 0xcc4);
        return;
      }
    }
  }
zdo_comm_signal_comm_done:
  iVar4 = core_globals_get();
  bVar1 = *(byte *)(iVar4 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar4 = core_globals_get();
  *(undefined2 *)(iVar4 + 0xcc2) = 0;
  iVar4 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (uVar5 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (uVar5 == 0) goto _L0;
    if (9 < uVar2) {
      uVar6 = zdo_comm_op_to_str_part_0();
      iVar4 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar4 + 0xcd4))(2,4,uVar6,*(code **)(iVar4 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar5);
_L0:
  iVar4 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = uVar5;
  (**(code **)(iVar4 + 0xcd8))(3,&uStack_18,*(code **)(iVar4 + 0xcd8));
  return;
}

