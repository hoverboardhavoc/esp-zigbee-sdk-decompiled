/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_handle_comm_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int bdb_handle_comm_signal(uint param_1,int *param_2)

{
  ushort uVar1;
  uint unaff_s0;
  char cVar2;
  short sVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  byte bVar11;
  uint uVar12;
  undefined4 unaff_s3;
  code *unaff_s4;
  undefined4 unaff_s5;
  uint unaff_s7;
  undefined2 auStack_32 [5];
  int iStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 2) {
    return 2;
  }
  if (param_1 < 3) {
    if (param_1 == 0) {
      iVar8 = core_globals_get();
      iVar8 = tasklet_post(iVar8 + 0xd3c);
      return iVar8;
    }
    iVar8 = core_globals_get();
    if (*(char *)(iVar8 + 0xd4f) != '\0') {
      return iVar8 + 0x1000;
    }
    if ((char)*param_2 == '\0') {
      return iVar8 + 0x1000;
    }
    iVar8 = core_globals_get();
    if ((*(char *)(iVar8 + 0xd4f) == '\0') &&
       (iVar8 = core_globals_get(), *(char *)(iVar8 + 0xd4e) == '\x06')) {
      iVar8 = core_globals_get();
      *(undefined1 *)(iVar8 + 0xd4f) = 1;
      iVar8 = zdo_dev_joined();
      if (iVar8 == 0) {
        iVar8 = zdo_dev_start_continue();
        return iVar8;
      }
      iVar8 = core_globals_get();
      tasklet_post(iVar8 + 0xd3c);
      iVar8 = 0;
    }
    else {
      iVar8 = 9;
    }
    return iVar8;
  }
  if (param_1 == 3) {
    unaff_s0 = (uint)*(byte *)(param_2 + 1);
    iStack_28 = *param_2;
    param_2 = (int *)0x1000;
    uStack_24 = param_1;
    iVar8 = core_globals_get(3);
    uVar12 = (uint)*(byte *)(iVar8 + 0xd4e);
    if (uVar12 != 2) {
      if (uVar12 < 3) {
        if (uVar12 != 0) {
          iVar8 = bdb_comm_initiator_handle_comm_done(unaff_s0);
          return iVar8;
        }
        if (uStack_24 < unaff_s0) {
          if (1 < (unaff_s0 - 7 & 0xff)) goto _L0;
        }
        else if (unaff_s0 < 2) goto _L0;
        if (iStack_28 == 0) {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 0;
          zdo_dev_set_joined(1);
          goto bdb_comm_finish_initialization;
        }
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xd4c) = 3;
        goto bdb_comm_finish_initialization;
      }
      if (uVar12 == 4) {
        iVar8 = core_globals_get();
        param_1 = bdb_comm_step_to_str(*(undefined1 *)(iVar8 + 0xd4e));
        pcVar10 = "%s: run in wrong state";
      }
      else {
        if (uVar12 == 5) {
          iVar8 = bdb_comm_target_handle_comm_done(unaff_s0);
          return iVar8;
        }
        if (uVar12 == uStack_24) {
          if (unaff_s0 == 1) {
            if (iStack_28 == 0) goto _L0;
          }
          else {
            if (unaff_s0 != 7) {
              iVar8 = core_globals_get();
              goto _L0;
            }
            if (iStack_28 == 0) {
              iVar8 = core_globals_get();
              *(undefined1 *)(iVar8 + 0xd4c) = 0;
              goto _L0;
            }
          }
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 5;
          iVar8 = core_globals_get();
          if ((*(ushort *)(iVar8 + 0xd5e) & 1) != 0) {
            iVar8 = core_globals_get();
            *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) & 0xfe;
            bdb_comm_network_formation_perform_form();
          }
_L0:
          iVar8 = core_globals_get();
          if (*(char *)(iVar8 + 0xd4c) != '\0') {
            uStack_14 = unaff_s3;
            pcStack_18 = unaff_s4;
            uStack_1c = unaff_s5;
            if (*(char *)(iVar8 + 0xd4c) != '\x01') goto bdb_comm_finish_network_formation;
            return iVar8 + 0x1000;
          }
          zdo_dev_set_joined(1);
          iVar8 = aps_secur_is_tc();
          uStack_14 = unaff_s3;
          pcStack_18 = unaff_s4;
          uStack_1c = unaff_s5;
          if (iVar8 == 0) goto bdb_comm_finish_network_formation;
          iVar8 = core_globals_get();
          *(ushort *)(iVar8 + 0x9bc) = *(ushort *)(iVar8 + 0x9bc) & 0xffe7 | 8;
          iVar8 = core_globals_get();
          uVar1 = *(ushort *)(iVar8 + 0xd5e);
          iVar8 = core_globals_get();
          *(ushort *)(iVar8 + 0x9bc) =
               *(ushort *)(iVar8 + 0x9bc) & 0xfff9 |
               (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
          uStack_14 = unaff_s3;
          pcStack_18 = unaff_s4;
          uStack_1c = unaff_s5;
          goto bdb_comm_finish_network_formation;
        }
        iVar8 = core_globals_get();
        param_1 = (uint)*(byte *)(iVar8 + 0xd4e);
        pcVar10 = "Invalid step: 0x%02x";
      }
      goto _L0;
    }
    if (unaff_s0 != 8) {
      iVar8 = iStack_28;
      if (8 < unaff_s0) goto _L0;
      if ((unaff_s0 != 2) && (2 < (unaff_s0 - 5 & 0xff))) goto _L0;
      if (iStack_28 != 0) {
_L0:
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xd4c) = 3;
        iVar8 = core_globals_get();
        if ((*(ushort *)(iVar8 + 0xd5e) & 1) != 0) {
          iVar8 = core_globals_get();
          *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) & 0xfe;
          bdb_comm_network_steering_perform_join();
        }
        goto _L0;
      }
      goto _L0;
    }
    if (iStack_28 != 0) goto _L0;
    iVar8 = aps_secur_is_centralized();
    if ((iVar8 != 0) && (iVar8 = core_globals_get(), (*(byte *)(iVar8 + 0xd5e) & 4) != 0)) {
      aps_secur_get_tc_address();
      iVar8 = nwk_address_short_by_extended(&uStack_1e);
      if (iVar8 == 0) {
        uStack_14 = 0;
        uStack_1c = CONCAT22(uStack_1e,uStack_1e);
        pcStack_18 = bdb_comm_network_steering_handle_node_desc_req_result;
        iVar8 = zdo_node_desc_req(&uStack_1c);
        if (iVar8 == 0) goto _L0;
      }
      iVar8 = core_globals_get();
      *(undefined1 *)(iVar8 + 0xd4c) = 10;
      bdb_comm_finish_network_steering_with_leave();
      goto _L0;
    }
    iVar8 = core_globals_get();
    pcVar10 = (char *)(iVar8 + 0x1000);
  }
  else {
    pcVar10 = "Invalid signal: 0x%02x";
_L0:
    log_write(1,"bdb_comm.c",pcVar10,param_1);
_L0:
    while( true ) {
      iVar8 = __assert_func(0,0,0,0);
_L0:
      if (unaff_s0 == 9) break;
_L0:
      iVar8 = core_globals_get();
_L0:
      uVar9 = bdb_comm_step_to_str(*(undefined1 *)(iVar8 + 0xd4e));
      log_write(1,"bdb_comm.c","%s: invalid op(%d)",uVar9,unaff_s0);
    }
    if (iVar8 != 0) {
      iVar8 = core_globals_get();
      *(char *)((int)param_2 + iVar8 + -0x2b4) = '\n';
      goto _L0;
    }
    iVar8 = core_globals_get();
    pcVar10 = (char *)(iVar8 + (int)param_2);
  }
  pcVar10[-0x2b4] = '\0';
_L0:
  iVar8 = core_globals_get();
  if (*(char *)(iVar8 + 0xd4c) != '\0') {
    if (*(char *)(iVar8 + 0xd4c) == '\x01') {
      return iVar8 + 0x1000;
    }
    iVar8 = core_globals_get();
    if (*(char *)(iVar8 + 0xd4c) == '\x01') {
      return iVar8 + 0x1000;
    }
    iVar8 = core_globals_get();
    if ((((*(char *)(iVar8 + 0xd4c) != '\0') && (iVar8 = nwk_is_joined(), iVar8 != 0)) &&
        (iVar8 = nwk_is_authed(), iVar8 != 0)) && (iVar8 = zdo_create_mgmt_req(0x34), iVar8 != 0)) {
      iVar7 = zdo_mgmt_req_get_param();
      *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) | 2;
      iVar7 = zdo_mgmt_req_get_param(iVar8);
      uStack_14 = 0;
      *(byte *)(iVar7 + 8) = *(byte *)(iVar7 + 8) & 0xfe;
      pcStack_18 = bdb_comm_network_steering_handle_leave_done;
      zdo_mgmt_req_set_user_ctx(iVar8,&pcStack_18);
      iVar8 = zdo_send_mgmt_req(iVar8,0);
      if (iVar8 == 0) {
        return 0;
      }
      if (iVar8 == 0xc) {
        return 0xc;
      }
    }
    do {
      bdb_comm_finish_step();
      iVar8 = core_globals_get();
      bdb_comm_put_app_signal(0x102,*(undefined1 *)(iVar8 + 0xd4c));
      uStack_24 = unaff_s7;
      uStack_1c = unaff_s5;
      pcStack_18 = unaff_s4;
      uStack_14 = unaff_s3;
_L0:
      uVar12 = 6;
      while (iVar8 = core_globals_get(), *(char *)(iVar8 + 0xd4f) != '\0') {
        iVar8 = core_globals_get();
        uVar4 = __ctzsi2(*(undefined1 *)(iVar8 + 0xd4f));
        uVar12 = uVar4 & 0xff;
        if (uVar4 == 6) {
          return 6;
        }
        iVar8 = core_globals_get();
        if (((int)(uint)*(byte *)(iVar8 + 0xd4f) >> (uVar4 & 0x1f) & 1U) == 0) goto _L0;
        if (uVar4 == 3) {
          iVar8 = core_globals_get();
          bVar11 = *(byte *)(iVar8 + 0xd4d) >> 1;
_L157:
          if ((bVar11 & 1) != 0) goto _L0;
        }
        else if ((int)uVar4 < 4) {
          if (uVar4 == 1) {
_L0:
            iVar8 = core_globals_get();
            bVar11 = *(byte *)(iVar8 + 0xd4d) >> 3;
            goto _L157;
          }
          if (uVar4 != 2) {
            uVar12 = 0;
            break;
          }
          iVar8 = core_globals_get();
          if ((*(byte *)(iVar8 + 0xd4d) & 1) != 0) {
            uVar12 = 2;
            goto _L0;
          }
        }
        else {
          if (uVar4 == 4) {
            iVar8 = core_globals_get();
            bVar11 = *(byte *)(iVar8 + 0xd4d) >> 2;
            goto _L157;
          }
          if (uVar4 == 5) goto _L0;
        }
_L0:
        iVar8 = core_globals_get();
        *(byte *)(iVar8 + 0xd4f) = ~(byte)(1 << (uVar4 & 0x1f)) & *(byte *)(iVar8 + 0xd4f);
      }
      if (uVar12 == 6) {
        return iVar8 + 0x1000;
      }
_L0:
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xd4f) = ~(byte)(1 << (uVar12 & 0x1f)) & *(byte *)(iVar8 + 0xd4f);
      iVar8 = core_globals_get();
      *(char *)(iVar8 + 0xd4e) = (char)uVar12;
      if (uVar12 == 3) {
        iVar8 = zdo_dev_joined();
        cVar2 = '\f';
        if (iVar8 == 0) {
          iVar8 = nwk_is_device_zczr();
          cVar2 = '\t';
          if (iVar8 != 0) {
            iVar8 = core_globals_get();
            cVar2 = '\x01';
            *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) | 1;
          }
        }
        iVar8 = core_globals_get();
        unaff_s7 = uStack_24;
        *(char *)(iVar8 + 0xd4c) = cVar2;
        if (cVar2 == '\x01') {
          iVar8 = core_globals_get();
          if (((*(byte *)(iVar8 + 0xd5e) & 1) != 0) &&
             (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xd54) != 0)) {
_L0:
            iVar8 = core_globals_get();
            *(undefined1 *)(iVar8 + 0xd4c) = 1;
            iVar8 = zdo_initiate_formation();
            return iVar8;
          }
          iVar8 = core_globals_get();
          if (*(int *)(iVar8 + 0xd58) != 0) {
            iVar8 = core_globals_get();
            *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) & 0xfe;
            goto _L0;
          }
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 5;
        }
bdb_comm_finish_network_formation:
        bdb_comm_finish_step();
        iVar8 = core_globals_get();
        bdb_comm_put_app_signal(0x103,*(undefined1 *)(iVar8 + 0xd4c));
        uStack_24 = unaff_s7;
        goto _L0;
      }
      if (3 < uVar12) {
        if (uVar12 != 4) {
          if (uVar12 == 5) {
            iVar8 = bdb_comm_touchlink_target();
            return iVar8;
          }
          iVar8 = core_globals_get();
          log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar8 + 0xd4e));
          goto _L0;
        }
        iVar8 = zdo_dev_joined();
        if (iVar8 == 0) {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 3;
        }
        else {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 9;
        }
        bdb_comm_finish_step();
        iVar8 = core_globals_get();
        bdb_comm_put_app_signal(0x104,*(undefined1 *)(iVar8 + 0xd4c));
        goto _L0;
      }
      if (uVar12 == 1) {
        iVar8 = bdb_comm_touchlink_initiator();
        return iVar8;
      }
      if (uVar12 != 2) {
        iVar8 = zdo_dev_joined();
        if (iVar8 == 0) {
          iVar8 = bdb_comm_is_factory_new();
          if (iVar8 == 0) {
            iVar8 = core_globals_get();
            *(undefined1 *)(iVar8 + 0xd4c) = 3;
            uVar12 = nwk_get_pan_channel();
            if (((uVar12 < 0x8000000) &&
                (uVar12 = nwk_get_pan_channel(), 0x7ff < (uVar12 & 0x7ffffff))) &&
               (iVar8 = nwk_get_panid(), iVar8 != 0xffff)) {
              piVar5 = (int *)nwk_get_extended_panid();
              if ((piVar5[1] + 1U != (uint)(*piVar5 == 0)) || (*piVar5 - 1U < 0xfffffffe)) {
                piVar5 = (int *)nwk_get_extended_address();
                if ((piVar5[1] + 1U != (uint)(*piVar5 == 0)) || (*piVar5 - 1U < 0xfffffffe)) {
                  iVar8 = nwk_get_short_address();
                  if (iVar8 != 0) goto _L0;
                  iVar8 = nwk_is_device_zc();
                  if (iVar8 != 0) {
                    do {
                      iVar8 = nwk_is_authed();
                      if ((iVar8 == 0) ||
                         (piVar5 = (int *)aps_secur_get_tc_address(), *piVar5 == 0 && piVar5[1] == 0
                         )) break;
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
                      iVar8 = core_globals_get();
                      *(undefined1 *)(iVar8 + 0xd4c) = 1;
                      iVar8 = nwk_is_device_zc();
                      if ((iVar8 == 0) &&
                         ((iVar8 = nwk_is_device_zr(), iVar8 == 0 ||
                          (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xd5c) << 0xc < 0)))) {
                        zdo_initiate_rejoin();
                        break;
                      }
                      iVar8 = core_globals_get();
                      *(byte *)(iVar8 + 0xb18) = *(byte *)(iVar8 + 0xb18) | 1;
                      uVar9 = nwk_get_extended_address();
                      uVar6 = nwk_get_short_address();
                      iVar8 = nwk_address_update(uVar9,uVar6,auStack_32);
                      if (iVar8 == 0) {
                        nwk_address_lock_ref(auStack_32[0]);
                        iVar8 = aps_secur_is_tc();
                        if (iVar8 != 0) {
                          iVar8 = core_globals_get();
                          *(ushort *)(iVar8 + 0x9bc) = *(ushort *)(iVar8 + 0x9bc) & 0xffe7 | 8;
                          iVar8 = core_globals_get();
                          uVar1 = *(ushort *)(iVar8 + 0xd5e);
                          iVar8 = core_globals_get();
                          *(ushort *)(iVar8 + 0x9bc) =
                               *(ushort *)(iVar8 + 0x9bc) & 0xfff9 |
                               (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
                        }
                        zdo_initiate_commissioning(0x80);
                        break;
                      }
_L0:
                      __assert_func(0,0,0,0);
_L0:
                      uVar12 = nwk_get_short_address();
                    } while (uVar12 < 0xfff8);
                  }
                }
              }
            }
            iVar8 = core_globals_get();
            unaff_s3 = uStack_14;
            unaff_s4 = pcStack_18;
            unaff_s5 = uStack_1c;
            unaff_s7 = uStack_24;
            if (*(char *)(iVar8 + 0xd4c) == '\x01') {
              return iVar8 + 0x1000;
            }
          }
          else {
            iVar8 = core_globals_get();
            *(undefined1 *)(iVar8 + 0xd4c) = 0;
            unaff_s3 = uStack_14;
            unaff_s4 = pcStack_18;
            unaff_s5 = uStack_1c;
            unaff_s7 = uStack_24;
          }
bdb_comm_finish_initialization:
          bdb_comm_finish_step();
          sVar3 = bdb_comm_is_factory_new();
          iVar8 = core_globals_get();
          bdb_comm_put_app_signal(0x101 - sVar3,*(undefined1 *)(iVar8 + 0xd4c));
          uStack_24 = unaff_s7;
          uStack_1c = unaff_s5;
          pcStack_18 = unaff_s4;
          uStack_14 = unaff_s3;
        }
        else {
          bdb_comm_finish_step();
        }
        goto _L0;
      }
      iVar8 = core_globals_get();
      *(undefined1 *)(iVar8 + 0xd4c) = 1;
      iVar8 = zdo_dev_joined();
      if (iVar8 != 0) goto bdb_comm_network_steering_on_network;
      iVar8 = core_globals_get();
      unaff_s3 = uStack_14;
      unaff_s4 = pcStack_18;
      unaff_s5 = uStack_1c;
      unaff_s7 = uStack_24;
      *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) | 1;
      iVar8 = core_globals_get();
      if (((*(byte *)(iVar8 + 0xd5e) & 1) != 0) &&
         (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xd54) != 0)) goto _L0;
      iVar8 = core_globals_get();
      if (*(int *)(iVar8 + 0xd58) != 0) {
        iVar8 = core_globals_get();
        *(byte *)(iVar8 + 0xd5e) = *(byte *)(iVar8 + 0xd5e) & 0xfe;
_L0:
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xd4c) = 1;
        iVar8 = zdo_initiate_join();
        return iVar8;
      }
      iVar8 = core_globals_get();
      *(undefined1 *)(iVar8 + 0xd4c) = 3;
    } while( true );
  }
  zdo_dev_set_joined(1);
bdb_comm_network_steering_on_network:
  uStack_1c = 0x1b4fffc;
  uStack_14 = 0;
  pcStack_18 = bdb_comm_permit_joining_req_cb;
  iVar8 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  if (iVar8 != 0) {
    uStack_20 = 0;
    uStack_24 = 0xffffffff;
    iVar8 = bdb_comm_permit_joining_req_cb(&uStack_24,0);
  }
  return iVar8;
}

