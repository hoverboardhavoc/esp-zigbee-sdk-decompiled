/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_comm_perform_next_op(void)

{
  byte bVar1;
  zdo_comm_operation_t op;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint8_t uStack_1d;
  uint uStack_1c;
  uint8_t scan_duration;
  nwk_join_req_t req;
  
  iVar3 = core_globals_get();
  if (*(short *)(iVar3 + 0xcc2) == 0) {
_L0:
    iVar3 = 0;
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
      iVar3 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
_L0:
      if (iVar3 == 0) {
        return;
      }
    }
    else {
      if ((int)uVar4 < 7) {
        if (uVar4 == 2) {
          iVar3 = core_globals_get();
          uStack_1c = *(uint *)(iVar3 + 8);
          uStack_1d = '\x03';
          iVar3 = core_globals_get();
          uVar4 = *(uint *)(iVar3 + 0xcdc);
          uVar5 = nwk_is_device_zed();
          zdo_comm_get_scan_duration(&uStack_1d);
          zdo_comm_get_channel_mask(&stack0xffffffe4);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          iVar3 = nwk_network_discovery(uStack_1d,uVar4 & 1 ^ 1,uVar5);
        }
        else if ((int)uVar4 < 3) {
          uStack_1c = 0;
          req.extpanid.field_0.u64._0_4_ = 0;
          iVar3 = core_globals_get();
          uStack_1c = *(uint *)(iVar3 + 8);
          req.extpanid.field_0.u8[0] = 3;
          iVar3 = aps_secur_is_centralized();
          if (iVar3 == 0) {
            req.extpanid.field_0.u64._0_4_ = req.extpanid.field_0.u64._0_4_ | 0x2000000;
          }
          else {
            req.extpanid.field_0.u64._0_4_ = req.extpanid.field_0.u64._0_4_ & 0xfdffffff;
            iVar3 = nwk_is_device_zc();
            if (iVar3 != 0) {
              nwk_get_extended_address();
              aps_secur_set_tc_address();
            }
          }
          zdo_comm_get_scan_duration((uint8_t *)&req);
          zdo_comm_get_channel_mask(&stack0xffffffe4);
          iVar3 = core_globals_get();
          uStack_1c = uStack_1c & 0xf8000000 | *(uint *)(iVar3 + 8) & uStack_1c & 0x7ffffff;
          iVar3 = nwk_network_formation_request(&stack0xffffffe4);
        }
        else {
          iVar3 = nwk_disc_table_next(0);
          if (iVar3 == 0) {
            iVar3 = 0x1ea;
            goto _L0;
          }
          uStack_1c = 0;
          req.extpanid.field_0.u64._0_4_ = 0;
          req.extpanid.field_0.u64._4_2_ = 0;
          req.extpanid.field_0.u8[6] = '\0';
          iVar6 = af_get_node_desc();
          req.extpanid.field_0.u8[5] = *(undefined1 *)(iVar6 + 2);
          nwk_address_get_extpanid(*(undefined1 *)(iVar3 + 8),&stack0xffffffe4);
          iVar3 = core_globals_get();
          req.extpanid.field_0.u8[4] = (char)((*(byte *)(iVar3 + 0xcdc) & 1) << 1);
          iVar3 = core_globals_get();
          req.extpanid.field_0.u8[6] =
               req.extpanid.field_0.u8[6] & 0xfe | *(char *)(iVar3 + 0xcc0) == '\x03';
          iVar3 = nwk_join_request(&stack0xffffffe4);
        }
        goto _L0;
      }
      if (uVar4 == 8) {
        uStack_1c = 0;
        req.extpanid.field_0.u64._0_4_ = 0;
        zdo_device_annce_req(&stack0xffffffe4);
        zdo_comm_perform_next_op();
        return;
      }
      if (uVar4 == 9) {
        iVar3 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
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
        iVar3 = nwk_start_router(&stack0xffffffe4);
        if ((iVar3 != 0) || (iVar3 = nwk_permit_joining(), iVar3 != 0)) goto _L0;
      }
      iVar3 = nwk_is_device_zed();
      if ((iVar3 == 0) || (iVar3 = nwk_start_end_device(), iVar3 == 0)) {
        iVar3 = core_globals_get();
        tasklet_post(iVar3 + 0xcc4);
        return;
      }
    }
  }
_L0:
  iVar6 = core_globals_get();
  bVar1 = *(byte *)(iVar6 + 0xcc0);
  uVar4 = (uint)bVar1;
  iVar6 = core_globals_get();
  *(undefined2 *)(iVar6 + 0xcc2) = 0;
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xcc0) = 0;
  if (uVar4 == 2) {
    if (iVar3 == 0) goto _L0;
    nwk_disc_table_reset();
  }
  else {
    op = nwk_disc_table_reset();
    if (iVar3 == 0) goto _L0;
    if (9 < uVar4) {
      pcVar2 = zdo_comm_op_to_str(op);
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0xcd4))(2,4,pcVar2,*(code **)(iVar3 + 0xcd4));
      return;
    }
  }
  log_write(2,"zdo_app_join.c","Comm failed in %s (0x%x)",
            *(undefined4 *)(operation_string_0 + uVar4 * 4),iVar3);
_L0:
  iVar6 = core_globals_get();
  req.extpanid.field_0.u8[4] = bVar1;
  req.extpanid.field_0.u64._0_4_ = iVar3;
  (**(code **)(iVar6 + 0xcd8))(3,&req,*(code **)(iVar6 + 0xcd8));
  return;
}

