/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> nwk_network_formation_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_network_formation_confirm(nwk_status_t status)

{
  byte bVar1;
  uint uVar2;
  zdo_comm_operation_t op;
  char *pcVar3;
  int iVar4;
  undefined3 in_register_00002029;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint in_a4;
  char *in_a5;
  uint8_t uStack_1d;
  uint32_t uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte bStack_12;
  
  if (CONCAT31(in_register_00002029,status) == 0) {
    uVar6 = nwk_secur_get_current_key_seq();
    iVar7 = nwk_secur_get_key_by_seq();
    if (iVar7 == 0) goto _L0;
    in_a5 = (char *)(iVar7 + 0xf);
    in_a4 = 0x10;
_L0:
    in_a4 = in_a4 - 1 & 0xff;
    if (*in_a5 == '\0') goto _L0;
    if (in_a4 == 0) goto _L0;
    do {
      iVar7 = nwk_secur_switch_key(uVar6);
      if (iVar7 == 0) {
        iVar7 = core_globals_get();
        if (*(short *)(iVar7 + 0xcc2) != 0) {
          iVar7 = core_globals_get();
          uVar5 = __ctzsi2(*(undefined2 *)(iVar7 + 0xcc2));
          if (uVar5 != 0) {
            iVar7 = core_globals_get();
            *(ushort *)(iVar7 + 0xcc2) = ~(ushort)(1 << (uVar5 & 0x1f)) & *(ushort *)(iVar7 + 0xcc2)
            ;
            iVar7 = core_globals_get();
            *(char *)(iVar7 + 0xcc0) = (char)uVar5;
            if (uVar5 == 6) {
              uVar5 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
            }
            else if ((int)uVar5 < 7) {
              if (uVar5 == 2) {
                iVar7 = core_globals_get();
                uStack_1c = *(uint *)(iVar7 + 8);
                uStack_1d = '\x03';
                iVar7 = core_globals_get();
                uVar5 = *(uint *)(iVar7 + 0xcdc);
                uVar6 = nwk_is_device_zed();
                zdo_comm_get_scan_duration(&uStack_1d);
                zdo_comm_get_channel_mask(&uStack_1c);
                iVar7 = core_globals_get();
                uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar7 + 8) & uStack_1c & 0x7ffffff;
                uVar5 = nwk_network_discovery(uStack_1d,uVar5 & 1 ^ 1,uVar6);
              }
              else if ((int)uVar5 < 3) {
                uStack_1c = 0;
                uStack_18 = 0;
                iVar7 = core_globals_get();
                uStack_1c = *(uint *)(iVar7 + 8);
                uStack_18 = CONCAT31(uStack_18._1_3_,3);
                iVar7 = aps_secur_is_centralized();
                if (iVar7 == 0) {
                  uStack_18 = uStack_18 | 0x2000000;
                }
                else {
                  uStack_18 = uStack_18 & 0xfdffffff;
                  iVar7 = nwk_is_device_zc();
                  if (iVar7 != 0) {
                    nwk_get_extended_address();
                    aps_secur_set_tc_address();
                  }
                }
                zdo_comm_get_scan_duration((uint8_t *)&uStack_18);
                zdo_comm_get_channel_mask(&uStack_1c);
                iVar7 = core_globals_get();
                uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar7 + 8) & uStack_1c & 0x7ffffff;
                uVar5 = nwk_network_formation_request(&uStack_1c);
              }
              else {
                iVar7 = nwk_disc_table_next(0);
                if (iVar7 == 0) {
                  uVar5 = 0x1ea;
                  goto zdo_comm_signal_comm_done;
                }
                uStack_1c = 0;
                uStack_18 = 0;
                uStack_14 = 0;
                bStack_12 = 0;
                iVar4 = af_get_node_desc();
                uStack_14._1_1_ = *(undefined1 *)(iVar4 + 2);
                nwk_address_get_extpanid(*(undefined1 *)(iVar7 + 8),&uStack_1c);
                iVar7 = core_globals_get();
                uStack_14 = CONCAT11(uStack_14._1_1_,(char)((*(byte *)(iVar7 + 0xcdc) & 1) << 1));
                iVar7 = core_globals_get();
                bStack_12 = bStack_12 & 0xfe | *(char *)(iVar7 + 0xcc0) == '\x03';
                uVar5 = nwk_join_request(&uStack_1c);
              }
            }
            else {
              if (uVar5 == 8) {
                uStack_1c = 0;
                uStack_18 = 0;
                zdo_device_annce_req(&uStack_1c);
                zdo_comm_perform_next_op();
                return;
              }
              if (uVar5 != 9) {
                if (uVar5 != 7) {
                  __assert_func(0,0,0,0);
                  goto _L0;
                }
                ds_save_common_data();
                iVar7 = nwk_is_device_zczr();
                if (iVar7 != 0) {
                  uStack_1c = uStack_1c & 0xff000000;
                  uVar5 = nwk_start_router(&uStack_1c);
                  if ((uVar5 != 0) || (uVar5 = nwk_permit_joining(), uVar5 != 0))
                  goto zdo_comm_signal_comm_done;
                }
                iVar7 = nwk_is_device_zed();
                if ((iVar7 == 0) || (uVar5 = nwk_start_end_device(), uVar5 == 0)) {
                  iVar7 = core_globals_get();
                  tasklet_post(iVar7 + 0xcc4);
                  return;
                }
                goto zdo_comm_signal_comm_done;
              }
              uVar5 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
            }
            if (uVar5 == 0) {
              return;
            }
            goto zdo_comm_signal_comm_done;
          }
        }
_L0:
        uVar5 = 0;
        goto zdo_comm_signal_comm_done;
      }
      __assert_func(0,0,0,0);
_L0:
      in_a5 = in_a5 + -1;
      if (in_a4 != 0) goto _L0;
_L0:
      nwk_secur_set_key(0,0);
      uVar6 = 0;
    } while( true );
  }
  uVar5 = CONCAT31(in_register_00002029,status) | 0x200;
zdo_comm_signal_comm_done:
  iVar7 = core_globals_get();
  bVar1 = *(byte *)(iVar7 + 0xcc0);
  uVar2 = (uint)bVar1;
  iVar7 = core_globals_get();
  *(undefined2 *)(iVar7 + 0xcc2) = 0;
  iVar7 = core_globals_get();
  *(undefined1 *)(iVar7 + 0xcc0) = 0;
  if (uVar2 == 2) {
    if (uVar5 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (uVar5 == 0) goto _L0;
    if (9 < uVar2) {
      pcVar3 = zdo_comm_op_to_str(op);
      iVar7 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar7 + 0xcd4))(2,4,pcVar3,*(code **)(iVar7 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar5);
_L0:
  iVar7 = core_globals_get();
  uStack_14 = CONCAT11(uStack_14._1_1_,bVar1);
  uStack_18 = uVar5;
  (**(code **)(iVar7 + 0xcd8))(3,&uStack_18,*(code **)(iVar7 + 0xcd8));
  return;
}

