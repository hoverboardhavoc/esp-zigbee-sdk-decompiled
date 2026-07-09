/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_permit_joining_req_cb(int *param_1)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  undefined2 auStack_32 [7];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (*param_1 != 0) {
    log_write(2,"bdb_comm.c","Broadcast PermitJoiningReq failed(0x%x)");
  }
  iVar8 = nwk_is_device_zczr();
  if ((iVar8 != 0) && (uVar9 = nwk_permit_joining(0xb4), uVar9 != 0)) {
    log_write(1,"bdb_comm.c","nwk_permit_joining(BDBC_MIN_COMMISSIONING_TIME) failed (c:%d,e:0x%x)",
              (int)uVar9 >> 8 & 0xff,uVar9 & 0xff);
  }
  iVar8 = core_globals_get();
  *(undefined1 *)(iVar8 + 0xd4c) = 0;
  do {
    bdb_comm_finish_step();
    iVar8 = core_globals_get();
    bdb_comm_put_app_signal(0x102,*(undefined1 *)(iVar8 + 0xd4c));
_L0:
    uVar9 = 6;
    while (iVar8 = core_globals_get(), *(char *)(iVar8 + 0xd4f) != '\0') {
      iVar8 = core_globals_get();
      uVar4 = __ctzsi2(*(undefined1 *)(iVar8 + 0xd4f));
      uVar9 = uVar4 & 0xff;
      if (uVar4 == 6) {
        return;
      }
      iVar8 = core_globals_get();
      if (((int)(uint)*(byte *)(iVar8 + 0xd4f) >> (uVar4 & 0x1f) & 1U) == 0) goto _L0;
      if (uVar4 == 3) {
        iVar8 = core_globals_get();
        bVar10 = *(byte *)(iVar8 + 0xd4d) >> 1;
_L157:
        if ((bVar10 & 1) != 0) goto _L0;
      }
      else if ((int)uVar4 < 4) {
        if (uVar4 == 1) {
_L0:
          iVar8 = core_globals_get();
          bVar10 = *(byte *)(iVar8 + 0xd4d) >> 3;
          goto _L157;
        }
        if (uVar4 != 2) {
          uVar9 = 0;
          break;
        }
        iVar8 = core_globals_get();
        if ((*(byte *)(iVar8 + 0xd4d) & 1) != 0) {
          uVar9 = 2;
          goto _L0;
        }
      }
      else {
        if (uVar4 == 4) {
          iVar8 = core_globals_get();
          bVar10 = *(byte *)(iVar8 + 0xd4d) >> 2;
          goto _L157;
        }
        if (uVar4 == 5) goto _L0;
      }
_L0:
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xd4f) = ~(byte)(1 << (uVar4 & 0x1f)) & *(byte *)(iVar8 + 0xd4f);
    }
    if (uVar9 == 6) {
      return;
    }
_L0:
    iVar8 = core_globals_get();
    *(byte *)(iVar8 + 0xd4f) = ~(byte)(1 << (uVar9 & 0x1f)) & *(byte *)(iVar8 + 0xd4f);
    iVar8 = core_globals_get();
    *(char *)(iVar8 + 0xd4e) = (char)uVar9;
    if (uVar9 == 3) {
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
      *(char *)(iVar8 + 0xd4c) = cVar2;
      if (cVar2 == '\x01') {
        iVar8 = core_globals_get();
        if (((*(byte *)(iVar8 + 0xd5e) & 1) != 0) &&
           (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xd54) != 0)) {
_L0:
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 1;
          zdo_initiate_formation();
          return;
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
      bdb_comm_finish_step();
      iVar8 = core_globals_get();
      bdb_comm_put_app_signal(0x103,*(undefined1 *)(iVar8 + 0xd4c));
      goto _L0;
    }
    if (3 < uVar9) {
      if (uVar9 != 4) {
        if (uVar9 == 5) {
          bdb_comm_touchlink_target();
          return;
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
    if (uVar9 == 1) {
      bdb_comm_touchlink_initiator();
      return;
    }
    if (uVar9 != 2) {
      iVar8 = zdo_dev_joined();
      if (iVar8 == 0) {
        iVar8 = bdb_comm_is_factory_new();
        if (iVar8 == 0) {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 3;
          uVar9 = nwk_get_pan_channel();
          if (((uVar9 < 0x8000000) && (uVar9 = nwk_get_pan_channel(), 0x7ff < (uVar9 & 0x7ffffff)))
             && (iVar8 = nwk_get_panid(), iVar8 != 0xffff)) {
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
                       (piVar5 = (int *)aps_secur_get_tc_address(), *piVar5 == 0 && piVar5[1] == 0))
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
                    uVar6 = nwk_get_extended_address();
                    uVar7 = nwk_get_short_address();
                    iVar8 = nwk_address_update(uVar6,uVar7,auStack_32);
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
                    uVar9 = nwk_get_short_address();
                  } while (uVar9 < 0xfff8);
                }
              }
            }
          }
          iVar8 = core_globals_get();
          if (*(char *)(iVar8 + 0xd4c) == '\x01') {
            return;
          }
        }
        else {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xd4c) = 0;
        }
        bdb_comm_finish_step();
        sVar3 = bdb_comm_is_factory_new();
        iVar8 = core_globals_get();
        bdb_comm_put_app_signal(0x101 - sVar3,*(undefined1 *)(iVar8 + 0xd4c));
      }
      else {
        bdb_comm_finish_step();
      }
      goto _L0;
    }
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar8 + 0xd4c) = 1;
    iVar8 = zdo_dev_joined();
    if (iVar8 != 0) {
      uStack_1c = 0x1b4fffc;
      uStack_14 = 0;
      pcStack_18 = bdb_comm_permit_joining_req_cb;
      iVar8 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
      if (iVar8 != 0) {
        uStack_20 = 0;
        uStack_24 = 0xffffffff;
        bdb_comm_permit_joining_req_cb(&uStack_24,0);
      }
      return;
    }
    iVar8 = core_globals_get();
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
      zdo_initiate_join();
      return;
    }
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar8 + 0xd4c) = 3;
  } while( true );
}

