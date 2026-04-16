/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> nwk_network_formation_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nwk_network_formation_confirm(nwk_status_t status)

{
  byte bVar1;
  uint uVar2;
  zdo_comm_operation_t op;
  undefined4 uVar3;
  int iVar4;
  undefined3 in_register_00002029;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char cVar8;
  uint8_t uStack_1d;
  uint32_t uStack_1c;
  uint uStack_18;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  if (CONCAT31(in_register_00002029,status) != 0) {
    uVar5 = CONCAT31(in_register_00002029,status) | 0x200;
    goto zdo_comm_signal_comm_done;
  }
  nwk_secur_get_current_key_seq();
  iVar6 = nwk_secur_get_key_by_seq();
  if (iVar6 != 0) {
    pcVar7 = (char *)(iVar6 + 0xf);
    cVar8 = '\x10';
    do {
      cVar8 = cVar8 + -1;
      if (*pcVar7 != '\0') {
        if (cVar8 != '\0') goto _L0;
        break;
      }
      pcVar7 = pcVar7 + -1;
    } while (cVar8 != '\0');
  }
  nwk_secur_set_key(0,0);
  iVar6 = nwk_secur_switch_key(0);
  if (iVar6 != 0) {
    __assert_func(0,0,0,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
_L0:
  iVar6 = core_globals_get();
  if (*(short *)(iVar6 + 0xd26) == 0) {
_L0:
    uVar5 = 0;
  }
  else {
    iVar6 = core_globals_get();
    uVar5 = __ctzsi2(*(undefined2 *)(iVar6 + 0xd26));
    if (uVar5 == 0) goto _L0;
    iVar6 = core_globals_get();
    *(ushort *)(iVar6 + 0xd26) = ~(ushort)(1 << (uVar5 & 0x1f)) & *(ushort *)(iVar6 + 0xd26);
    iVar6 = core_globals_get();
    *(char *)(iVar6 + 0xd24) = (char)uVar5;
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
          iVar6 = core_globals_get();
          uStack_1c = *(uint *)(iVar6 + 8);
          uStack_1d = '\x03';
          iVar6 = core_globals_get();
          uVar5 = *(uint *)(iVar6 + 0xd40);
          uVar3 = nwk_is_device_zed();
          zdo_comm_get_scan_duration(&uStack_1d);
          zdo_comm_get_channel_mask(&uStack_1c);
          iVar6 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar6 + 8) & uStack_1c & 0x7ffffff;
          uVar5 = nwk_network_discovery(uStack_1d,uVar5 & 1 ^ 1,uVar3);
        }
        else if ((int)uVar5 < 3) {
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
          uVar5 = nwk_network_formation_request(&uStack_1c);
        }
        else {
          iVar6 = nwk_disc_table_next(0);
          if (iVar6 == 0) {
            uVar5 = 0x1ea;
            goto zdo_comm_signal_comm_done;
          }
          bStack_14 = 0;
          bStack_13 = 0x84;
          uStack_1c = 0;
          uStack_18 = 0;
          bStack_12 = 0;
          iVar4 = core_globals_get();
          if (*(char *)(iVar4 + 0x9ee) != '\0') {
            bStack_13 = bStack_13 | 8;
          }
          iVar4 = nwk_is_device_zczr();
          if (iVar4 != 0) {
            bStack_13 = bStack_13 | 2;
          }
          nwk_address_get_extpanid(*(undefined1 *)(iVar6 + 8),&uStack_1c);
          iVar6 = core_globals_get();
          _bStack_14 = CONCAT11(bStack_13,(char)((*(byte *)(iVar6 + 0xd40) & 1) << 1));
          iVar6 = core_globals_get();
          bStack_12 = bStack_12 & 0xfe | *(char *)(iVar6 + 0xd24) == '\x03';
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
      iVar6 = nwk_is_device_zczr();
      if (iVar6 != 0) {
        uStack_1c = uStack_1c & 0xff000000;
        uVar5 = nwk_start_router(&uStack_1c);
        if ((uVar5 != 0) || (uVar5 = nwk_permit_joining(), uVar5 != 0))
        goto zdo_comm_signal_comm_done;
      }
      iVar6 = nwk_is_device_zed();
      if ((iVar6 == 0) || (uVar5 = nwk_start_end_device(), uVar5 == 0)) {
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
    if (uVar5 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (uVar5 == 0) goto _L0;
    if (9 < uVar2) {
      pcVar7 = zdo_comm_op_to_str(op);
      iVar6 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar6 + 0xd38))(2,4,pcVar7,*(code **)(iVar6 + 0xd38));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar2 * 4),uVar5);
_L0:
  iVar6 = core_globals_get();
  _bStack_14 = CONCAT11(bStack_13,bVar1);
  uStack_18 = uVar5;
  (**(code **)(iVar6 + 0xd3c))(3,&uStack_18,*(code **)(iVar6 + 0xd3c));
  return;
}

