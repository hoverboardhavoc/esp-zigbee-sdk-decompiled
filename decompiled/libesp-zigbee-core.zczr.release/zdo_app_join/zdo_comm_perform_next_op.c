/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_perform_next_op(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 uStack_1d;
  uint uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  iVar3 = core_globals_get();
  if (*(short *)(iVar3 + 0xcc2) == 0) {
_L0:
    uVar4 = 0;
  }
  else {
    iVar3 = core_globals_get();
    uVar4 = __ctzsi2(*(undefined2 *)(iVar3 + 0xcc2));
    if (uVar4 == 0) goto _L0;
    iVar3 = core_globals_get();
    *(ushort *)(iVar3 + 0xcc2) = ~(ushort)(1 << (uVar4 & 0x1f)) & *(ushort *)(iVar3 + 0xcc2);
    iVar3 = core_globals_get();
    *(char *)(iVar3 + 0xcc0) = (char)uVar4;
    if (uVar4 == 6) {
      uVar4 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
_L0:
      if (uVar4 == 0) {
        return;
      }
    }
    else {
      if ((int)uVar4 < 7) {
        if (uVar4 == 2) {
          iVar3 = core_globals_get();
          uStack_1c = *(uint *)(iVar3 + 8);
          uStack_1d = 3;
          iVar3 = core_globals_get();
          uVar4 = *(uint *)(iVar3 + 0xcdc);
          iVar3 = core_globals_get();
          uVar6 = 0;
          if ((*(uint *)(iVar3 + 0xcdc) & 1) == 0) {
            uVar6 = nwk_is_device_zed();
          }
          zdo_comm_get_scan_duration_isra_0(&uStack_1d);
          zdo_comm_get_channel_mask_isra_0(&uStack_1c);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          uVar4 = nwk_network_discovery(uStack_1d,uVar4 & 1 ^ 1,uVar6);
        }
        else if ((int)uVar4 < 3) {
          uStack_1c = 0;
          uStack_18 = 0;
          iVar3 = core_globals_get();
          uStack_1c = *(uint *)(iVar3 + 8);
          uStack_18 = CONCAT31(uStack_18._1_3_,3);
          iVar3 = aps_secur_is_centralized();
          if (iVar3 == 0) {
            uStack_18 = uStack_18 | 0x2000000;
          }
          else {
            uStack_18 = uStack_18 & 0xfdffffff;
            iVar3 = nwk_is_device_zc();
            if (iVar3 != 0) {
              nwk_get_extended_address();
              aps_secur_set_tc_address();
            }
          }
          zdo_comm_get_scan_duration_isra_0(&uStack_18);
          zdo_comm_get_channel_mask_isra_0(&uStack_1c);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          uVar4 = nwk_network_formation_request(&uStack_1c);
        }
        else {
          iVar3 = nwk_disc_table_next(0);
          if (iVar3 == 0) {
            uVar4 = 0x1ea;
            goto _L0;
          }
          uStack_1c = 0;
          uStack_18 = 0;
          uStack_14 = 0;
          bStack_12 = 0;
          iVar5 = af_get_node_desc();
          uStack_14._1_1_ = *(undefined1 *)(iVar5 + 2);
          nwk_address_get_extpanid(*(undefined1 *)(iVar3 + 8),&uStack_1c);
          iVar3 = core_globals_get();
          uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar3 + 0xcdc) & 1) << 1));
          iVar3 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar3 + 0xcc0) == '\x03';
          uVar4 = nwk_join_request(&uStack_1c);
        }
        goto _L0;
      }
      if (uVar4 == 8) {
        uStack_1c = 0;
        uStack_18 = 0;
        zdo_device_annce_req(&uStack_1c);
        zdo_comm_perform_next_op();
        return;
      }
      if (uVar4 == 9) {
        uVar4 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
        goto _L0;
      }
      if (uVar4 != 7) {
        __assert_func(0,0,0,0);
        goto _L0;
      }
      ds_save_common_data();
      iVar3 = nwk_is_device_zczr();
      if (iVar3 != 0) {
        uStack_1c = uStack_1c & 0xff000000;
        uVar4 = nwk_start_router(&uStack_1c);
        if ((uVar4 != 0) || (uVar4 = nwk_permit_joining(), uVar4 != 0)) goto _L0;
      }
      iVar3 = nwk_is_device_zed();
      if ((iVar3 == 0) || (uVar4 = nwk_start_end_device(), uVar4 == 0)) {
        iVar3 = core_globals_get();
        tasklet_post(iVar3 + 0xcc4);
        return;
      }
    }
  }
_L0:
  iVar3 = core_globals_get();
  bVar1 = *(byte *)(iVar3 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xcc2) = 0;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (uVar4 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    nwk_disc_table_reset();
    if (uVar4 == 0) goto _L0;
    if (9 < uVar2) {
      uVar6 = zdo_comm_op_to_str_part_0();
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0xcd4))(2,4,uVar6,*(code **)(iVar3 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar4);
_L0:
  iVar3 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = uVar4;
  (**(code **)(iVar3 + 0xcd8))(3,&uStack_18,*(code **)(iVar3 + 0xcd8));
  return;
}

