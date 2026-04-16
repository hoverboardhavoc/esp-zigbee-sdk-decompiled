/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  if (cnf->status != 0) {
    if ((cnf->join_method == '\0') || (cnf->join_method == '\x03')) {
      iVar6 = core_globals_get();
      *(ushort *)(iVar6 + 0xd26) = *(ushort *)(iVar6 + 0xd26) | 0x20;
      goto _L0;
    }
    uVar7 = cnf->status | 0x200;
    goto zdo_comm_signal_comm_done;
  }
_L0:
  iVar6 = core_globals_get();
  if (*(short *)(iVar6 + 0xd26) == 0) {
_L0:
    uVar7 = 0;
  }
  else {
    iVar6 = core_globals_get();
    uVar7 = __ctzsi2(*(undefined2 *)(iVar6 + 0xd26));
    if (uVar7 == 0) goto _L0;
    iVar6 = core_globals_get();
    *(ushort *)(iVar6 + 0xd26) = ~(ushort)(1 << (uVar7 & 0x1f)) & *(ushort *)(iVar6 + 0xd26);
    iVar6 = core_globals_get();
    *(char *)(iVar6 + 0xd24) = (char)uVar7;
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
          uVar7 = *(uint *)(iVar6 + 0xd40);
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
          bStack_14 = 0;
          bStack_13 = 0x84;
          uStack_1c = 0;
          uStack_18 = 0;
          bStack_12 = 0;
          iVar5 = core_globals_get();
          if (*(char *)(iVar5 + 0x9ee) != '\0') {
            bStack_13 = bStack_13 | 8;
          }
          iVar5 = nwk_is_device_zczr();
          if (iVar5 != 0) {
            bStack_13 = bStack_13 | 2;
          }
          nwk_address_get_extpanid(*(undefined1 *)(iVar6 + 8),&uStack_1c);
          iVar6 = core_globals_get();
          _bStack_14 = CONCAT11(bStack_13,(char)((*(byte *)(iVar6 + 0xd40) & 1) << 1));
          iVar6 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar6 + 0xd24) == '\x03';
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
        tasklet_post(iVar6 + 0xd28);
        return;
      }
    }
  }
zdo_comm_signal_comm_done:
  iVar6 = core_globals_get();
  bVar1 = *(byte *)(iVar6 + 0xd24);
  uVar2 = (uint)bVar1;
  iVar6 = core_globals_get();
  *(undefined2 *)(iVar6 + 0xd26) = 0;
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xd24) = 0;
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
      (**(code **)(iVar6 + 0xd38))(2,4,pcVar3,*(code **)(iVar6 + 0xd38));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar7);
_L0:
  iVar6 = core_globals_get();
  _bStack_14 = CONCAT11(bStack_13,bVar1);
  uStack_18 = uVar7;
  (**(code **)(iVar6 + 0xd3c))(3,&uStack_18,*(code **)(iVar6 + 0xd3c));
  return;
}

