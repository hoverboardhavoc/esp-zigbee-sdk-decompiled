/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> nwk_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_join_confirm(nwk_join_cnf_t *cnf)

{
  byte bVar1;
  uint uVar2;
  zdo_comm_operation_t op;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint8_t uStack_1d;
  uint32_t uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  if (cnf->status != 0) {
    if ((cnf->join_method == '\0') || (cnf->join_method == '\x03')) {
      iVar6 = core_globals_get();
      *(ushort *)(iVar6 + 0xcc2) = *(ushort *)(iVar6 + 0xcc2) | 0x20;
      goto _L0;
    }
    uVar7 = cnf->status | 0x200;
    goto zdo_comm_signal_comm_done;
  }
_L0:
  iVar6 = core_globals_get();
  if (*(short *)(iVar6 + 0xcc2) == 0) {
_L0:
    uVar7 = 0;
  }
  else {
    iVar6 = core_globals_get();
    uVar7 = __ctzsi2(*(undefined2 *)(iVar6 + 0xcc2));
    if (uVar7 == 0) goto _L0;
    iVar6 = core_globals_get();
    *(ushort *)(iVar6 + 0xcc2) = ~(ushort)(1 << (uVar7 & 0x1f)) & *(ushort *)(iVar6 + 0xcc2);
    iVar6 = core_globals_get();
    *(char *)(iVar6 + 0xcc0) = (char)uVar7;
    if (uVar7 == 6) {
      uVar7 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
_L0:
      if (uVar7 == 0) {
        return;
      }
    }
    else {
      if ((int)uVar7 < 7) {
        if (uVar7 == 2) {
          iVar6 = core_globals_get();
          uStack_1c = *(uint *)(iVar6 + 8);
          uStack_1d = '\x03';
          iVar6 = core_globals_get();
          uVar7 = *(uint *)(iVar6 + 0xcdc);
          uVar4 = nwk_is_device_zed();
          zdo_comm_get_scan_duration(&uStack_1d);
          zdo_comm_get_channel_mask(&uStack_1c);
          iVar6 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar6 + 8) & uStack_1c & 0x7ffffff;
          uVar7 = nwk_network_discovery(uStack_1d,uVar7 & 1 ^ 1,uVar4);
        }
        else if ((int)uVar7 < 3) {
          uStack_1c = 0;
          uStack_18 = 0;
          iVar6 = core_globals_get();
          uStack_1c = *(uint *)(iVar6 + 8);
          uStack_18 = CONCAT31(uStack_18._1_3_,3);
          iVar6 = aps_secur_is_centralized();
          if (iVar6 == 0) {
            uStack_18 = uStack_18 | 0x2000000;
          }
          else {
            uStack_18 = uStack_18 & 0xfdffffff;
            iVar6 = nwk_is_device_zc();
            if (iVar6 != 0) {
              nwk_get_extended_address();
              aps_secur_set_tc_address();
            }
          }
          zdo_comm_get_scan_duration((uint8_t *)&uStack_18);
          zdo_comm_get_channel_mask(&uStack_1c);
          iVar6 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar6 + 8) & uStack_1c & 0x7ffffff;
          uVar7 = nwk_network_formation_request(&uStack_1c);
        }
        else {
          iVar6 = nwk_disc_table_next(0);
          if (iVar6 == 0) {
            uVar7 = 0x1ea;
            goto zdo_comm_signal_comm_done;
          }
          uStack_1c = 0;
          uStack_18 = 0;
          uStack_14 = 0;
          bStack_12 = 0;
          iVar5 = af_get_node_desc();
          uStack_14._1_1_ = *(undefined1 *)(iVar5 + 2);
          nwk_address_get_extpanid(*(undefined1 *)(iVar6 + 8),&uStack_1c);
          iVar6 = core_globals_get();
          uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar6 + 0xcdc) & 1) << 1));
          iVar6 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar6 + 0xcc0) == '\x03';
          uVar7 = nwk_join_request(&uStack_1c);
        }
        goto _L0;
      }
      if (uVar7 == 8) {
        uStack_1c = 0;
        uStack_18 = 0;
        zdo_device_annce_req(&uStack_1c);
        zdo_comm_perform_next_op();
        return;
      }
      if (uVar7 == 9) {
        uVar7 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
        goto _L0;
      }
      if (uVar7 != 7) {
        __assert_func(0,0,0,0);
        goto _L0;
      }
      ds_save_common_data();
      iVar6 = nwk_is_device_zczr();
      if (iVar6 != 0) {
        uStack_1c = uStack_1c & 0xff000000;
        uVar7 = nwk_start_router(&uStack_1c);
        if ((uVar7 != 0) || (uVar7 = nwk_permit_joining(), uVar7 != 0))
        goto zdo_comm_signal_comm_done;
      }
      iVar6 = nwk_is_device_zed();
      if ((iVar6 == 0) || (uVar7 = nwk_start_end_device(), uVar7 == 0)) {
        iVar6 = core_globals_get();
        tasklet_post(iVar6 + 0xcc4);
        return;
      }
    }
  }
zdo_comm_signal_comm_done:
  iVar6 = core_globals_get();
  bVar1 = *(byte *)(iVar6 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar6 = core_globals_get();
  *(undefined2 *)(iVar6 + 0xcc2) = 0;
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (uVar7 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (uVar7 == 0) goto _L0;
    if (9 < uVar2) {
      pcVar3 = zdo_comm_op_to_str(op);
      iVar6 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar6 + 0xcd4))(2,4,pcVar3,*(code **)(iVar6 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar7);
_L0:
  iVar6 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = uVar7;
  (**(code **)(iVar6 + 0xcd8))(3,&uStack_18,*(code **)(iVar6 + 0xcd8));
  return;
}

