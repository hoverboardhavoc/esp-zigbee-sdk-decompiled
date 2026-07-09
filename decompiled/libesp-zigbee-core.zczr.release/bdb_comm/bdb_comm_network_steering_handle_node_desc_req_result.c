/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_network_steering_handle_node_desc_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_network_steering_handle_node_desc_req_result(int *param_1)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  undefined4 unaff_s3;
  code *unaff_s4;
  undefined2 auStack_32 [7];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if ((*param_1 == 0) && (*(char *)param_1[1] == '\0')) {
    if (*(ushort *)((char *)param_1[1] + 0xe) >> 9 < 0x15) {
      iVar10 = core_globals_get();
      *(undefined1 *)(iVar10 + 0xd4c) = 0;
      zdo_dev_set_joined(1);
    }
    else {
      iVar10 = core_globals_get();
      *(undefined1 *)(iVar10 + 0xd4c) = 1;
      zdo_initiate_commissioning(0x200);
    }
  }
  else {
    iVar10 = core_globals_get();
    *(undefined1 *)(iVar10 + 0xd4c) = 10;
  }
  iVar10 = core_globals_get();
  if (*(char *)(iVar10 + 0xd4c) == '\x01') {
    return;
  }
  iVar10 = core_globals_get();
  if (*(char *)(iVar10 + 0xd4c) == '\x01') {
    return;
  }
  iVar10 = core_globals_get();
  if ((((*(char *)(iVar10 + 0xd4c) != '\0') && (iVar10 = nwk_is_joined(), iVar10 != 0)) &&
      (iVar10 = nwk_is_authed(), iVar10 != 0)) && (iVar10 = zdo_create_mgmt_req(0x34), iVar10 != 0))
  {
    iVar9 = zdo_mgmt_req_get_param();
    *(byte *)(iVar9 + 8) = *(byte *)(iVar9 + 8) | 2;
    iVar9 = zdo_mgmt_req_get_param(iVar10);
    uStack_14 = 0;
    *(byte *)(iVar9 + 8) = *(byte *)(iVar9 + 8) & 0xfe;
    pcStack_18 = bdb_comm_network_steering_handle_leave_done;
    zdo_mgmt_req_set_user_ctx(iVar10,&pcStack_18);
    iVar10 = zdo_send_mgmt_req(iVar10,0);
    if (iVar10 == 0) {
      return;
    }
    if (iVar10 == 0xc) {
      return;
    }
  }
  do {
    bdb_comm_finish_step();
    iVar10 = core_globals_get();
    bdb_comm_put_app_signal(0x102,*(undefined1 *)(iVar10 + 0xd4c));
    pcStack_18 = unaff_s4;
    uStack_14 = unaff_s3;
_L0:
    uVar3 = 6;
    while (iVar10 = core_globals_get(), *(char *)(iVar10 + 0xd4f) != '\0') {
      iVar10 = core_globals_get();
      uVar5 = __ctzsi2(*(undefined1 *)(iVar10 + 0xd4f));
      uVar3 = uVar5 & 0xff;
      if (uVar5 == 6) {
        return;
      }
      iVar10 = core_globals_get();
      if (((int)(uint)*(byte *)(iVar10 + 0xd4f) >> (uVar5 & 0x1f) & 1U) == 0) goto _L0;
      if (uVar5 == 3) {
        iVar10 = core_globals_get();
        bVar11 = *(byte *)(iVar10 + 0xd4d) >> 1;
_L157:
        if ((bVar11 & 1) != 0) goto _L0;
      }
      else if ((int)uVar5 < 4) {
        if (uVar5 == 1) {
_L0:
          iVar10 = core_globals_get();
          bVar11 = *(byte *)(iVar10 + 0xd4d) >> 3;
          goto _L157;
        }
        if (uVar5 != 2) {
          uVar3 = 0;
          break;
        }
        iVar10 = core_globals_get();
        if ((*(byte *)(iVar10 + 0xd4d) & 1) != 0) {
          uVar3 = 2;
          goto _L0;
        }
      }
      else {
        if (uVar5 == 4) {
          iVar10 = core_globals_get();
          bVar11 = *(byte *)(iVar10 + 0xd4d) >> 2;
          goto _L157;
        }
        if (uVar5 == 5) goto _L0;
      }
_L0:
      iVar10 = core_globals_get();
      *(byte *)(iVar10 + 0xd4f) = ~(byte)(1 << (uVar5 & 0x1f)) & *(byte *)(iVar10 + 0xd4f);
    }
    if (uVar3 == 6) {
      return;
    }
_L0:
    iVar10 = core_globals_get();
    *(byte *)(iVar10 + 0xd4f) = ~(byte)(1 << (uVar3 & 0x1f)) & *(byte *)(iVar10 + 0xd4f);
    iVar10 = core_globals_get();
    *(char *)(iVar10 + 0xd4e) = (char)uVar3;
    if (uVar3 == 3) {
      iVar10 = zdo_dev_joined();
      cVar2 = '\f';
      if (iVar10 == 0) {
        iVar10 = nwk_is_device_zczr();
        cVar2 = '\t';
        if (iVar10 != 0) {
          iVar10 = core_globals_get();
          cVar2 = '\x01';
          *(byte *)(iVar10 + 0xd5e) = *(byte *)(iVar10 + 0xd5e) | 1;
        }
      }
      iVar10 = core_globals_get();
      *(char *)(iVar10 + 0xd4c) = cVar2;
      if (cVar2 == '\x01') {
        iVar10 = core_globals_get();
        if (((*(byte *)(iVar10 + 0xd5e) & 1) != 0) &&
           (iVar10 = core_globals_get(), *(int *)(iVar10 + 0xd54) != 0)) {
_L0:
          iVar10 = core_globals_get();
          *(undefined1 *)(iVar10 + 0xd4c) = 1;
          zdo_initiate_formation();
          return;
        }
        iVar10 = core_globals_get();
        if (*(int *)(iVar10 + 0xd58) != 0) {
          iVar10 = core_globals_get();
          *(byte *)(iVar10 + 0xd5e) = *(byte *)(iVar10 + 0xd5e) & 0xfe;
          goto _L0;
        }
        iVar10 = core_globals_get();
        *(undefined1 *)(iVar10 + 0xd4c) = 5;
      }
      bdb_comm_finish_step();
      iVar10 = core_globals_get();
      bdb_comm_put_app_signal(0x103,*(undefined1 *)(iVar10 + 0xd4c));
      goto _L0;
    }
    if (3 < uVar3) {
      if (uVar3 != 4) {
        if (uVar3 == 5) {
          bdb_comm_touchlink_target();
          return;
        }
        iVar10 = core_globals_get();
        log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar10 + 0xd4e));
        goto _L0;
      }
      iVar10 = zdo_dev_joined();
      if (iVar10 == 0) {
        iVar10 = core_globals_get();
        *(undefined1 *)(iVar10 + 0xd4c) = 3;
      }
      else {
        iVar10 = core_globals_get();
        *(undefined1 *)(iVar10 + 0xd4c) = 9;
      }
      bdb_comm_finish_step();
      iVar10 = core_globals_get();
      bdb_comm_put_app_signal(0x104,*(undefined1 *)(iVar10 + 0xd4c));
      goto _L0;
    }
    if (uVar3 == 1) {
      bdb_comm_touchlink_initiator();
      return;
    }
    if (uVar3 != 2) {
      iVar10 = zdo_dev_joined();
      if (iVar10 == 0) {
        iVar10 = bdb_comm_is_factory_new();
        if (iVar10 == 0) {
          iVar10 = core_globals_get();
          *(undefined1 *)(iVar10 + 0xd4c) = 3;
          uVar3 = nwk_get_pan_channel();
          if (((uVar3 < 0x8000000) && (uVar3 = nwk_get_pan_channel(), 0x7ff < (uVar3 & 0x7ffffff)))
             && (iVar10 = nwk_get_panid(), iVar10 != 0xffff)) {
            piVar6 = (int *)nwk_get_extended_panid();
            if ((piVar6[1] + 1U != (uint)(*piVar6 == 0)) || (*piVar6 - 1U < 0xfffffffe)) {
              piVar6 = (int *)nwk_get_extended_address();
              if ((piVar6[1] + 1U != (uint)(*piVar6 == 0)) || (*piVar6 - 1U < 0xfffffffe)) {
                iVar10 = nwk_get_short_address();
                if (iVar10 != 0) goto _L0;
                iVar10 = nwk_is_device_zc();
                if (iVar10 != 0) {
                  do {
                    iVar10 = nwk_is_authed();
                    if ((iVar10 == 0) ||
                       (piVar6 = (int *)aps_secur_get_tc_address(), *piVar6 == 0 && piVar6[1] == 0))
                    break;
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
                    iVar10 = core_globals_get();
                    *(undefined1 *)(iVar10 + 0xd4c) = 1;
                    iVar10 = nwk_is_device_zc();
                    if ((iVar10 == 0) &&
                       ((iVar10 = nwk_is_device_zr(), iVar10 == 0 ||
                        (iVar10 = core_globals_get(), *(int *)(iVar10 + 0xd5c) << 0xc < 0)))) {
                      zdo_initiate_rejoin();
                      break;
                    }
                    iVar10 = core_globals_get();
                    *(byte *)(iVar10 + 0xb18) = *(byte *)(iVar10 + 0xb18) | 1;
                    uVar7 = nwk_get_extended_address();
                    uVar8 = nwk_get_short_address();
                    iVar10 = nwk_address_update(uVar7,uVar8,auStack_32);
                    if (iVar10 == 0) {
                      nwk_address_lock_ref(auStack_32[0]);
                      iVar10 = aps_secur_is_tc();
                      if (iVar10 != 0) {
                        iVar10 = core_globals_get();
                        *(ushort *)(iVar10 + 0x9bc) = *(ushort *)(iVar10 + 0x9bc) & 0xffe7 | 8;
                        iVar10 = core_globals_get();
                        uVar1 = *(ushort *)(iVar10 + 0xd5e);
                        iVar10 = core_globals_get();
                        *(ushort *)(iVar10 + 0x9bc) =
                             *(ushort *)(iVar10 + 0x9bc) & 0xfff9 |
                             (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
                      }
                      zdo_initiate_commissioning(0x80);
                      break;
                    }
_L0:
                    __assert_func(0,0,0,0);
_L0:
                    uVar3 = nwk_get_short_address();
                  } while (uVar3 < 0xfff8);
                }
              }
            }
          }
          iVar10 = core_globals_get();
          if (*(char *)(iVar10 + 0xd4c) == '\x01') {
            return;
          }
        }
        else {
          iVar10 = core_globals_get();
          *(undefined1 *)(iVar10 + 0xd4c) = 0;
        }
        bdb_comm_finish_step();
        sVar4 = bdb_comm_is_factory_new();
        iVar10 = core_globals_get();
        bdb_comm_put_app_signal(0x101 - sVar4,*(undefined1 *)(iVar10 + 0xd4c));
      }
      else {
        bdb_comm_finish_step();
      }
      goto _L0;
    }
    iVar10 = core_globals_get();
    *(undefined1 *)(iVar10 + 0xd4c) = 1;
    iVar10 = zdo_dev_joined();
    if (iVar10 != 0) {
      uStack_1c = 0x1b4fffc;
      uStack_14 = 0;
      pcStack_18 = bdb_comm_permit_joining_req_cb;
      iVar10 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
      if (iVar10 != 0) {
        uStack_20 = 0;
        uStack_24 = 0xffffffff;
        bdb_comm_permit_joining_req_cb(&uStack_24,0);
      }
      return;
    }
    iVar10 = core_globals_get();
    unaff_s3 = uStack_14;
    unaff_s4 = pcStack_18;
    *(byte *)(iVar10 + 0xd5e) = *(byte *)(iVar10 + 0xd5e) | 1;
    iVar10 = core_globals_get();
    if (((*(byte *)(iVar10 + 0xd5e) & 1) != 0) &&
       (iVar10 = core_globals_get(), *(int *)(iVar10 + 0xd54) != 0)) goto _L0;
    iVar10 = core_globals_get();
    if (*(int *)(iVar10 + 0xd58) != 0) {
      iVar10 = core_globals_get();
      *(byte *)(iVar10 + 0xd5e) = *(byte *)(iVar10 + 0xd5e) & 0xfe;
_L0:
      iVar10 = core_globals_get();
      *(undefined1 *)(iVar10 + 0xd4c) = 1;
      zdo_initiate_join();
      return;
    }
    iVar10 = core_globals_get();
    *(undefined1 *)(iVar10 + 0xd4c) = 3;
  } while( true );
}

