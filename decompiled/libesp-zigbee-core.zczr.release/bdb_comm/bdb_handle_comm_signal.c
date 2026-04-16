/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_handle_comm_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void bdb_handle_comm_signal(zdo_comm_signal_t signal,void *param)

{
  ushort uVar1;
  char *unaff_s0;
  char cVar2;
  uint uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined3 in_register_00002029;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  byte bVar12;
  ezb_zdo_node_desc_req_callback_t unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  char *unaff_s7;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined1 uStack_32;
  int iStack_28;
  ezb_zdo_nwk_mgmt_permit_joining_req_result_t eStack_24;
  undefined4 uStack_1c;
  ezb_shortaddr_t tc_short;
  zdo_node_desc_req_t req;
  
  pcVar10 = (char *)CONCAT31(in_register_00002029,signal);
  if (pcVar10 == (char *)0x2) {
    return;
  }
  if (pcVar10 < (char *)0x3) {
    eStack_24.error = (ezb_err_t)unaff_s7;
    uStack_1c = unaff_s5;
    req._0_4_ = unaff_s4;
    req.cb = unaff_s3;
    if (pcVar10 == (char *)0x0) goto _L0;
    iVar9 = core_globals_get();
    if (*(char *)(iVar9 + 0xda3) != '\0') {
      return;
    }
                    /* WARNING: Load size is inaccurate */
    if (*param == '\0') {
      return;
    }
    iVar9 = core_globals_get();
    if ((*(char *)(iVar9 + 0xda3) == '\0') &&
       (iVar9 = core_globals_get(), *(char *)(iVar9 + 0xda2) == '\x06')) {
      iVar9 = core_globals_get();
      *(undefined1 *)(iVar9 + 0xda3) = 1;
      iVar9 = zdo_dev_joined();
      if (iVar9 == 0) {
        zdo_dev_start_continue();
        return;
      }
      bdb_comm_perform_next_step();
    }
    return;
  }
  if (pcVar10 == (char *)0x3) {
    unaff_s0 = (char *)(uint)*(byte *)((int)param + 4);
                    /* WARNING: Load size is inaccurate */
    iStack_28 = *param;
    param = (void *)0x1000;
    eStack_24.error = (ezb_err_t)pcVar10;
    iVar9 = core_globals_get(3);
    pcVar10 = (char *)(uint)*(byte *)(iVar9 + 0xda2);
    if (pcVar10 != (char *)0x2) {
      if (pcVar10 < (char *)0x3) {
        if (pcVar10 != (char *)0x0) {
          bdb_comm_initiator_handle_comm_done(unaff_s0);
          return;
        }
        if ((uint)eStack_24.error < unaff_s0) {
          if (1 < ((uint)(unaff_s0 + -7) & 0xff)) goto _L0;
        }
        else if (unaff_s0 < (char *)0x2) goto _L0;
        if (iStack_28 == 0) {
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 0;
          goto bdb_comm_finish_initialization;
        }
        iVar9 = core_globals_get();
        *(undefined1 *)(iVar9 + 0xda0) = 3;
        goto bdb_comm_finish_initialization;
      }
      if (pcVar10 == (char *)0x4) {
        iVar9 = core_globals_get();
        pcVar10 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar9 + 0xda2));
        pcVar11 = "%s: run in wrong state";
      }
      else {
        if (pcVar10 == (char *)0x5) {
          bdb_comm_target_handle_comm_done(unaff_s0);
          return;
        }
        if (pcVar10 == (char *)eStack_24.error) {
          if (unaff_s0 == (char *)0x1) {
            if (iStack_28 == 0) goto _L0;
          }
          else {
            if (unaff_s0 != (char *)0x7) {
              iVar9 = core_globals_get();
              goto _L0;
            }
            if (iStack_28 == 0) {
              iVar9 = core_globals_get();
              *(undefined1 *)(iVar9 + 0xda0) = 0;
              goto _L0;
            }
          }
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 5;
          iVar9 = core_globals_get();
          if ((*(ushort *)(iVar9 + 0xdb2) & 1) != 0) {
            iVar9 = core_globals_get();
            *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
            bdb_comm_network_formation_perform_form();
          }
_L0:
          iVar9 = core_globals_get();
          if (*(char *)(iVar9 + 0xda0) != '\0') {
            req.cb = unaff_s3;
            req._0_4_ = unaff_s4;
            uStack_1c = unaff_s5;
            if (*(char *)(iVar9 + 0xda0) != '\x01') goto bdb_comm_finish_network_formation;
            return;
          }
          zdo_dev_set_joined(1);
          iVar9 = aps_secur_is_tc();
          req.cb = unaff_s3;
          req._0_4_ = unaff_s4;
          uStack_1c = unaff_s5;
          if (iVar9 == 0) goto bdb_comm_finish_network_formation;
          iVar9 = core_globals_get();
          *(ushort *)(iVar9 + 0x9bc) = *(ushort *)(iVar9 + 0x9bc) & 0xffe7 | 8;
          iVar9 = core_globals_get();
          uVar1 = *(ushort *)(iVar9 + 0xdb2);
          iVar9 = core_globals_get();
          *(ushort *)(iVar9 + 0x9bc) =
               *(ushort *)(iVar9 + 0x9bc) & 0xfff9 |
               (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
          req.cb = unaff_s3;
          req._0_4_ = unaff_s4;
          uStack_1c = unaff_s5;
          goto bdb_comm_finish_network_formation;
        }
        iVar9 = core_globals_get();
        pcVar10 = (char *)(uint)*(byte *)(iVar9 + 0xda2);
        pcVar11 = "Invalid step: 0x%02x";
      }
      goto _L0;
    }
    if (unaff_s0 != (char *)0x8) {
      iVar9 = iStack_28;
      if ((char *)0x8 < unaff_s0) goto _L0;
      if ((unaff_s0 != (char *)0x2) && (2 < ((uint)(unaff_s0 + -5) & 0xff))) goto _L0;
      if (iStack_28 != 0) {
_L0:
        iVar9 = core_globals_get();
        *(undefined1 *)(iVar9 + 0xda0) = 3;
        iVar9 = core_globals_get();
        if ((*(ushort *)(iVar9 + 0xdb2) & 1) != 0) {
          iVar9 = core_globals_get();
          *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
          bdb_comm_network_steering_perform_join();
        }
        goto _L0;
      }
      goto _L0;
    }
    if (iStack_28 != 0) goto _L0;
    iVar9 = aps_secur_is_centralized();
    if ((iVar9 != 0) && (iVar9 = core_globals_get(), (*(byte *)(iVar9 + 0xdb2) & 4) != 0)) {
      aps_secur_get_tc_address();
      iVar9 = nwk_address_short_by_extended((undefined1 *)((int)&eStack_24.rsp + 2));
      if (iVar9 == 0) {
        req.cb = (ezb_zdo_node_desc_req_callback_t)0x0;
        uStack_1c = CONCAT22(eStack_24.rsp._2_2_,eStack_24.rsp._2_2_);
        req._0_4_ = bdb_comm_network_steering_handle_node_desc_req_result;
        iVar9 = zdo_node_desc_req(&stack0xffffffe4);
        if (iVar9 == 0) goto _L0;
      }
      iVar9 = core_globals_get();
      *(undefined1 *)(iVar9 + 0xda0) = 10;
      bdb_comm_finish_network_steering_with_leave();
      goto _L0;
    }
    iVar9 = core_globals_get();
    iVar9 = iVar9 + 0x1000;
  }
  else {
    pcVar11 = "Invalid signal: 0x%02x";
_L0:
    log_write(1,"bdb_comm.c",pcVar11,pcVar10);
_L0:
    while( true ) {
      iVar9 = __assert_func(0,0,0,0);
_L0:
      if (unaff_s0 == (char *)0x9) break;
_L0:
      iVar9 = core_globals_get();
_L0:
      pcVar10 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar9 + 0xda2));
      log_write(1,"bdb_comm.c","%s: invalid op(%d)",pcVar10,unaff_s0);
    }
    unaff_s0 = (char *)0x9;
    if (iVar9 != 0) {
      iVar9 = core_globals_get();
      *(undefined1 *)((int)param + iVar9 + -0x260) = 10;
      goto _L0;
    }
    iVar9 = core_globals_get();
    iVar9 = iVar9 + (int)param;
  }
  *(undefined1 *)(iVar9 + -0x260) = 0;
_L0:
  iVar9 = core_globals_get();
  if (*(char *)(iVar9 + 0xda0) != '\0') {
    if (*(char *)(iVar9 + 0xda0) == '\x01') {
      return;
    }
    if ((char *)0x5 < unaff_s0) {
      bdb_comm_finish_network_steering_with_leave();
      return;
    }
    do {
      bdb_comm_finish_step();
      iVar9 = core_globals_get();
      bdb_comm_put_app_signal(0x102,*(bdb_comm_status_t *)(iVar9 + 0xda0));
      eStack_24.error = (ezb_err_t)unaff_s7;
      uStack_1c = unaff_s5;
      req._0_4_ = unaff_s4;
      req.cb = unaff_s3;
_L0:
      uVar3 = 6;
      while (iVar9 = core_globals_get(), *(char *)(iVar9 + 0xda3) != '\0') {
        iVar9 = core_globals_get();
        uVar5 = __ctzsi2(*(undefined1 *)(iVar9 + 0xda3));
        uVar3 = uVar5 & 0xff;
        if (uVar5 == 6) {
          return;
        }
        iVar9 = core_globals_get();
        if (((int)(uint)*(byte *)(iVar9 + 0xda3) >> (uVar5 & 0x1f) & 1U) == 0) goto _L0;
        if (uVar5 == 3) {
          iVar9 = core_globals_get();
          bVar12 = *(byte *)(iVar9 + 0xda1) >> 1;
_L147:
          if ((bVar12 & 1) != 0) goto _L0;
        }
        else if ((int)uVar5 < 4) {
          if (uVar5 == 1) {
_L0:
            iVar9 = core_globals_get();
            bVar12 = *(byte *)(iVar9 + 0xda1) >> 3;
            goto _L147;
          }
          if (uVar5 != 2) {
            uVar3 = 0;
            break;
          }
          iVar9 = core_globals_get();
          if ((*(byte *)(iVar9 + 0xda1) & 1) != 0) {
            uVar3 = 2;
            goto _L0;
          }
        }
        else {
          if (uVar5 == 4) {
            iVar9 = core_globals_get();
            bVar12 = *(byte *)(iVar9 + 0xda1) >> 2;
            goto _L147;
          }
          if (uVar5 == 5) goto _L0;
        }
_L0:
        iVar9 = core_globals_get();
        *(byte *)(iVar9 + 0xda3) = ~(byte)(1 << (uVar5 & 0x1f)) & *(byte *)(iVar9 + 0xda3);
      }
      if (uVar3 == 6) {
        return;
      }
_L0:
      iVar9 = core_globals_get();
      *(byte *)(iVar9 + 0xda3) = ~(byte)(1 << (uVar3 & 0x1f)) & *(byte *)(iVar9 + 0xda3);
      iVar9 = core_globals_get();
      *(char *)(iVar9 + 0xda2) = (char)uVar3;
      if (uVar3 == 3) {
        iVar9 = zdo_dev_joined();
        cVar2 = '\f';
        if (iVar9 == 0) {
          iVar9 = nwk_is_device_zczr();
          cVar2 = '\t';
          if (iVar9 != 0) {
            iVar9 = core_globals_get();
            cVar2 = '\x01';
            *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) | 1;
          }
        }
        iVar9 = core_globals_get();
        unaff_s7 = (char *)eStack_24.error;
        *(char *)(iVar9 + 0xda0) = cVar2;
        if (cVar2 == '\x01') {
          iVar9 = core_globals_get();
          if (((*(byte *)(iVar9 + 0xdb2) & 1) != 0) &&
             (iVar9 = core_globals_get(), *(int *)(iVar9 + 0xda8) != 0)) {
_L0:
            iVar9 = core_globals_get();
            *(undefined1 *)(iVar9 + 0xda0) = 1;
            zdo_initiate_formation();
            return;
          }
          iVar9 = core_globals_get();
          if (*(int *)(iVar9 + 0xdac) != 0) {
            iVar9 = core_globals_get();
            *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
            goto _L0;
          }
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 5;
        }
bdb_comm_finish_network_formation:
        bdb_comm_finish_step();
        iVar9 = core_globals_get();
        bdb_comm_put_app_signal(0x103,*(bdb_comm_status_t *)(iVar9 + 0xda0));
        eStack_24.error = (ezb_err_t)unaff_s7;
        goto _L0;
      }
      if (3 < uVar3) {
        if (uVar3 != 4) {
          if (uVar3 == 5) {
            bdb_comm_touchlink_target();
            return;
          }
          iVar9 = core_globals_get();
          log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar9 + 0xda2));
          goto _L0;
        }
        iVar9 = zdo_dev_joined();
        if (iVar9 == 0) {
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 3;
        }
        else {
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 9;
        }
        bdb_comm_finish_step();
        iVar9 = core_globals_get();
        bdb_comm_put_app_signal(0x104,*(bdb_comm_status_t *)(iVar9 + 0xda0));
        goto _L0;
      }
      if (uVar3 == 1) {
        bdb_comm_touchlink_initiator();
        return;
      }
      if (uVar3 != 2) {
        iVar9 = zdo_dev_joined();
        if (iVar9 == 0) {
          _Var4 = bdb_comm_is_factory_new();
          if (CONCAT31(extraout_var_00,_Var4) == 0) {
            iVar9 = core_globals_get();
            *(undefined1 *)(iVar9 + 0xda0) = 3;
            uVar3 = nwk_get_pan_channel();
            if (((uVar3 < 0x8000000) && (uVar3 = nwk_get_pan_channel(), 0x7ff < (uVar3 & 0x7ffffff))
                ) && (iVar9 = nwk_get_panid(), iVar9 != 0xffff)) {
              piVar6 = (int *)nwk_get_extended_panid();
              if ((piVar6[1] + 1U != (uint)(*piVar6 == 0)) || (*piVar6 - 1U < 0xfffffffe)) {
                piVar6 = (int *)nwk_get_extended_address();
                if ((piVar6[1] + 1U != (uint)(*piVar6 == 0)) || (*piVar6 - 1U < 0xfffffffe)) {
                  iVar9 = nwk_get_short_address();
                  if (iVar9 != 0) goto _L0;
                  iVar9 = nwk_is_device_zc();
                  if (iVar9 != 0) {
                    while (iVar9 = nwk_is_authed(), iVar9 != 0) {
                      nwk_get_panid();
                      nwk_set_panid();
                      nwk_get_short_address();
                      nwk_set_short_address();
                      nwk_get_extended_address();
                      nwk_set_extended_address();
                      nwk_get_pan_channel();
                      nwk_set_pan_channel();
                      nwk_get_rx_on_when_idle();
                      nwk_set_rx_on_when_idle();
                      iVar9 = nwk_is_device_zc();
                      if ((iVar9 == 0) &&
                         ((iVar9 = nwk_is_device_zr(), iVar9 == 0 ||
                          (iVar9 = core_globals_get(), *(int *)(iVar9 + 0xdb0) << 0xc < 0)))) {
                        iVar9 = core_globals_get();
                        *(undefined1 *)(iVar9 + 0xda0) = 1;
                        zdo_initiate_rejoin();
                        break;
                      }
                      iVar9 = core_globals_get();
                      *(undefined1 *)(iVar9 + 0xda0) = 0;
                      iVar9 = core_globals_get();
                      *(byte *)(iVar9 + 0xb18) = *(byte *)(iVar9 + 0xb18) | 1;
                      uVar7 = nwk_get_extended_address();
                      uVar8 = nwk_get_short_address();
                      iVar9 = nwk_address_update(uVar7,uVar8,&uStack_36);
                      if (iVar9 == 0) {
                        nwk_address_lock_ref(uStack_36);
                        uStack_34 = 0;
                        uStack_32 = 0;
                        iVar9 = nwk_start_router(&uStack_34);
                        if (iVar9 == 0) {
                          zdo_dev_set_joined(1);
                          iVar9 = aps_secur_is_tc();
                          if (iVar9 != 0) {
                            iVar9 = core_globals_get();
                            *(ushort *)(iVar9 + 0x9bc) = *(ushort *)(iVar9 + 0x9bc) & 0xffe7 | 8;
                            iVar9 = core_globals_get();
                            uVar1 = *(ushort *)(iVar9 + 0xdb2);
                            iVar9 = core_globals_get();
                            *(ushort *)(iVar9 + 0x9bc) =
                                 *(ushort *)(iVar9 + 0x9bc) & 0xfff9 |
                                 (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
                          }
                          break;
                        }
                      }
_L0:
                      __assert_func(0,0,0,0);
_L0:
                      uVar3 = nwk_get_short_address();
                      if (0xfff7 < uVar3) break;
                    }
                  }
                }
              }
            }
            iVar9 = core_globals_get();
            unaff_s3 = req.cb;
            unaff_s4 = req._0_4_;
            unaff_s5 = uStack_1c;
            unaff_s7 = (char *)eStack_24.error;
            if (*(char *)(iVar9 + 0xda0) == '\x01') {
              return;
            }
          }
          else {
            iVar9 = core_globals_get();
            *(undefined1 *)(iVar9 + 0xda0) = 0;
            unaff_s3 = req.cb;
            unaff_s4 = req._0_4_;
            unaff_s5 = uStack_1c;
            unaff_s7 = (char *)eStack_24.error;
          }
bdb_comm_finish_initialization:
          bdb_comm_finish_step();
          _Var4 = bdb_comm_is_factory_new();
          iVar9 = core_globals_get();
          bdb_comm_put_app_signal
                    (0x101 - (short)CONCAT31(extraout_var,_Var4),
                     *(bdb_comm_status_t *)(iVar9 + 0xda0));
          eStack_24.error = (ezb_err_t)unaff_s7;
          uStack_1c = unaff_s5;
          req._0_4_ = unaff_s4;
          req.cb = unaff_s3;
        }
        else {
          bdb_comm_finish_step();
        }
        goto _L0;
      }
      iVar9 = core_globals_get();
      *(undefined1 *)(iVar9 + 0xda0) = 1;
      iVar9 = zdo_dev_joined();
      if (iVar9 != 0) goto bdb_comm_network_steering_on_network;
      iVar9 = core_globals_get();
      unaff_s3 = req.cb;
      unaff_s4 = req._0_4_;
      unaff_s5 = uStack_1c;
      unaff_s7 = (char *)eStack_24.error;
      *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) | 1;
      iVar9 = core_globals_get();
      if (((*(byte *)(iVar9 + 0xdb2) & 1) != 0) &&
         (iVar9 = core_globals_get(), *(int *)(iVar9 + 0xda8) != 0)) goto _L0;
      iVar9 = core_globals_get();
      if (*(int *)(iVar9 + 0xdac) != 0) {
        iVar9 = core_globals_get();
        *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
_L0:
        iVar9 = core_globals_get();
        *(undefined1 *)(iVar9 + 0xda0) = 1;
        zdo_initiate_join();
        return;
      }
      iVar9 = core_globals_get();
      *(undefined1 *)(iVar9 + 0xda0) = 3;
    } while( true );
  }
  zdo_dev_set_joined(1);
bdb_comm_network_steering_on_network:
  uStack_1c = 0x1b4fffc;
  req.cb = (ezb_zdo_node_desc_req_callback_t)0x0;
  req._0_4_ = bdb_comm_permit_joining_req_cb;
  iVar9 = zdo_nwk_mgmt_permit_joining_req(&stack0xffffffe4);
  if (iVar9 != 0) {
    eStack_24.rsp = (ezb_zdp_nwk_mgmt_permit_joining_rsp_field_t *)0x0;
    eStack_24.error = -1;
    bdb_comm_permit_joining_req_cb(&eStack_24,(void *)0x0);
  }
  return;
}

