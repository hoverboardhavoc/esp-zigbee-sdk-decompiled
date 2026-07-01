/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_handle_op_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_handle_op_result(ezb_err_t error,void *unused)

{
  byte bVar1;
  uint uVar2;
  zdo_comm_operation_t op;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  void *extraout_a1;
  void *extraout_a1_00;
  void *extraout_a1_01;
  void *extraout_a1_02;
  void *extraout_a1_03;
  void *extraout_a1_04;
  void *extraout_a1_05;
  void *extraout_a1_06;
  void *extraout_a1_07;
  void *extraout_a1_08;
  void *extraout_a1_09;
  uint8_t uStack_1d;
  uint32_t uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  if (error != 0) goto zdo_comm_signal_comm_done;
  iVar3 = core_globals_get();
  unused = extraout_a1;
  if (*(short *)(iVar3 + 0xcc2) == 0) {
_L0:
    error = 0;
  }
  else {
    iVar3 = core_globals_get();
    uVar2 = __ctzsi2(*(undefined2 *)(iVar3 + 0xcc2));
    unused = extraout_a1_00;
    if (uVar2 == 0) goto _L0;
    iVar3 = core_globals_get();
    *(ushort *)(iVar3 + 0xcc2) = ~(ushort)(1 << (uVar2 & 0x1f)) & *(ushort *)(iVar3 + 0xcc2);
    iVar3 = core_globals_get();
    *(char *)(iVar3 + 0xcc0) = (char)uVar2;
    if (uVar2 == 6) {
      error = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
      unused = extraout_a1_04;
_L0:
      if (error == 0) {
        return;
      }
    }
    else {
      if ((int)uVar2 < 7) {
        if (uVar2 == 2) {
          iVar3 = core_globals_get();
          uStack_1c = *(uint *)(iVar3 + 8);
          uStack_1d = '\x03';
          iVar3 = core_globals_get();
          uVar2 = *(uint *)(iVar3 + 0xcdc);
          uVar5 = nwk_is_device_zed();
          zdo_comm_get_scan_duration(&uStack_1d);
          zdo_comm_get_channel_mask(&uStack_1c);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          error = nwk_network_discovery(uStack_1d,uVar2 & 1 ^ 1,uVar5);
          unused = extraout_a1_02;
        }
        else if ((int)uVar2 < 3) {
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
          zdo_comm_get_scan_duration((uint8_t *)&uStack_18);
          zdo_comm_get_channel_mask(&uStack_1c);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          error = nwk_network_formation_request(&uStack_1c);
          unused = extraout_a1_09;
        }
        else {
          iVar3 = nwk_disc_table_next(0);
          if (iVar3 == 0) {
            error = 0x1ea;
            unused = extraout_a1_01;
            goto zdo_comm_signal_comm_done;
          }
          uStack_1c = 0;
          uStack_18 = 0;
          uStack_14 = 0;
          bStack_12 = 0;
          iVar6 = af_get_node_desc();
          uStack_14._1_1_ = *(undefined1 *)(iVar6 + 2);
          nwk_address_get_extpanid(*(undefined1 *)(iVar3 + 8),&uStack_1c);
          iVar3 = core_globals_get();
          uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar3 + 0xcdc) & 1) << 1));
          iVar3 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar3 + 0xcc0) == '\x03';
          error = nwk_join_request(&uStack_1c);
          unused = extraout_a1_03;
        }
        goto _L0;
      }
      if (uVar2 == 8) {
        uStack_1c = 0;
        uStack_18 = 0;
        zdo_device_annce_req(&uStack_1c);
        zdo_comm_perform_next_op();
        return;
      }
      if (uVar2 == 9) {
        error = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
        unused = extraout_a1_08;
        goto _L0;
      }
      if (uVar2 != 7) {
        unused = (void *)__assert_func(0,0,0,0);
        goto _L0;
      }
      ds_save_common_data();
      iVar3 = nwk_is_device_zczr();
      if (iVar3 != 0) {
        uStack_1c = uStack_1c & 0xff000000;
        error = nwk_start_router(&uStack_1c);
        unused = extraout_a1_05;
        if ((error != 0) || (error = nwk_permit_joining(), unused = extraout_a1_06, error != 0))
        goto zdo_comm_signal_comm_done;
      }
      iVar3 = nwk_is_device_zed();
      if ((iVar3 == 0) || (error = nwk_start_end_device(), unused = extraout_a1_07, error == 0)) {
        iVar3 = core_globals_get();
        tasklet_post(iVar3 + 0xcc4);
        return;
      }
    }
  }
zdo_comm_signal_comm_done:
  iVar3 = core_globals_get(unused);
  bVar1 = *(byte *)(iVar3 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xcc2) = 0;
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (error == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (error == 0) goto _L0;
    if (9 < uVar2) {
      pcVar4 = zdo_comm_op_to_str(op);
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0xcd4))(2,4,pcVar4,*(code **)(iVar3 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),error);
_L0:
  iVar3 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = error;
  (**(code **)(iVar3 + 0xcd8))(3,&uStack_18,*(code **)(iVar3 + 0xcd8));
  return;
}

