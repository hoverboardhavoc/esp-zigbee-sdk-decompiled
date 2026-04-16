/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_permit_joining_req_cb
               (ezb_zdo_nwk_mgmt_permit_joining_req_result_t *result,void *unused)

{
  ushort uVar1;
  char cVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  uint uVar4;
  undefined3 extraout_var_00;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined1 uStack_32;
  ezb_zdo_nwk_mgmt_permit_joining_req_result_t eStack_24;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (result->error != 0) {
    unused = (void *)log_write(2,"bdb_comm.c","Broadcast PermitJoiningReq failed(0x%x)");
  }
  iVar8 = nwk_is_device_zczr(unused);
  if ((iVar8 != 0) && (uVar9 = nwk_permit_joining(0xb4), uVar9 != 0)) {
    log_write(1,"bdb_comm.c","nwk_permit_joining(BDBC_MIN_COMMISSIONING_TIME) failed (c:%d,e:0x%x)",
              (int)uVar9 >> 8 & 0xff,uVar9 & 0xff);
  }
  iVar8 = core_globals_get();
  *(undefined1 *)(iVar8 + 0xda0) = 0;
  do {
    bdb_comm_finish_step();
    iVar8 = core_globals_get();
    bdb_comm_put_app_signal(0x102,*(bdb_comm_status_t *)(iVar8 + 0xda0));
_L0:
    uVar9 = 6;
    while (iVar8 = core_globals_get(), *(char *)(iVar8 + 0xda3) != '\0') {
      iVar8 = core_globals_get();
      uVar4 = __ctzsi2(*(undefined1 *)(iVar8 + 0xda3));
      uVar9 = uVar4 & 0xff;
      if (uVar4 == 6) {
        return;
      }
      iVar8 = core_globals_get();
      if (((int)(uint)*(byte *)(iVar8 + 0xda3) >> (uVar4 & 0x1f) & 1U) == 0) goto _L0;
      if (uVar4 == 3) {
        iVar8 = core_globals_get();
        bVar10 = *(byte *)(iVar8 + 0xda1) >> 1;
_L147:
        if ((bVar10 & 1) != 0) goto _L0;
      }
      else if ((int)uVar4 < 4) {
        if (uVar4 == 1) {
_L0:
          iVar8 = core_globals_get();
          bVar10 = *(byte *)(iVar8 + 0xda1) >> 3;
          goto _L147;
        }
        if (uVar4 != 2) {
          uVar9 = 0;
          break;
        }
        iVar8 = core_globals_get();
        if ((*(byte *)(iVar8 + 0xda1) & 1) != 0) {
          uVar9 = 2;
          goto _L0;
        }
      }
      else {
        if (uVar4 == 4) {
          iVar8 = core_globals_get();
          bVar10 = *(byte *)(iVar8 + 0xda1) >> 2;
          goto _L147;
        }
        if (uVar4 == 5) goto _L0;
      }
_L0:
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xda3) = ~(byte)(1 << (uVar4 & 0x1f)) & *(byte *)(iVar8 + 0xda3);
    }
    if (uVar9 == 6) {
      return;
    }
_L0:
    iVar8 = core_globals_get();
    *(byte *)(iVar8 + 0xda3) = ~(byte)(1 << (uVar9 & 0x1f)) & *(byte *)(iVar8 + 0xda3);
    iVar8 = core_globals_get();
    *(char *)(iVar8 + 0xda2) = (char)uVar9;
    if (uVar9 == 3) {
      iVar8 = zdo_dev_joined();
      cVar2 = '\f';
      if (iVar8 == 0) {
        iVar8 = nwk_is_device_zczr();
        cVar2 = '\t';
        if (iVar8 != 0) {
          iVar8 = core_globals_get();
          cVar2 = '\x01';
          *(byte *)(iVar8 + 0xdb2) = *(byte *)(iVar8 + 0xdb2) | 1;
        }
      }
      iVar8 = core_globals_get();
      *(char *)(iVar8 + 0xda0) = cVar2;
      if (cVar2 == '\x01') {
        iVar8 = core_globals_get();
        if (((*(byte *)(iVar8 + 0xdb2) & 1) != 0) &&
           (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xda8) != 0)) {
_L0:
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xda0) = 1;
          zdo_initiate_formation();
          return;
        }
        iVar8 = core_globals_get();
        if (*(int *)(iVar8 + 0xdac) != 0) {
          iVar8 = core_globals_get();
          *(byte *)(iVar8 + 0xdb2) = *(byte *)(iVar8 + 0xdb2) & 0xfe;
          goto _L0;
        }
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xda0) = 5;
      }
      bdb_comm_finish_step();
      iVar8 = core_globals_get();
      bdb_comm_put_app_signal(0x103,*(bdb_comm_status_t *)(iVar8 + 0xda0));
      goto _L0;
    }
    if (3 < uVar9) {
      if (uVar9 != 4) {
        if (uVar9 == 5) {
          bdb_comm_touchlink_target();
          return;
        }
        iVar8 = core_globals_get();
        log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar8 + 0xda2));
        goto _L0;
      }
      iVar8 = zdo_dev_joined();
      if (iVar8 == 0) {
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xda0) = 3;
      }
      else {
        iVar8 = core_globals_get();
        *(undefined1 *)(iVar8 + 0xda0) = 9;
      }
      bdb_comm_finish_step();
      iVar8 = core_globals_get();
      bdb_comm_put_app_signal(0x104,*(bdb_comm_status_t *)(iVar8 + 0xda0));
      goto _L0;
    }
    if (uVar9 == 1) {
      bdb_comm_touchlink_initiator();
      return;
    }
    if (uVar9 != 2) {
      iVar8 = zdo_dev_joined();
      if (iVar8 == 0) {
        _Var3 = bdb_comm_is_factory_new();
        if (CONCAT31(extraout_var_00,_Var3) == 0) {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xda0) = 3;
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
                  while (iVar8 = nwk_is_authed(), iVar8 != 0) {
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
                    iVar8 = nwk_is_device_zc();
                    if ((iVar8 == 0) &&
                       ((iVar8 = nwk_is_device_zr(), iVar8 == 0 ||
                        (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xdb0) << 0xc < 0)))) {
                      iVar8 = core_globals_get();
                      *(undefined1 *)(iVar8 + 0xda0) = 1;
                      zdo_initiate_rejoin();
                      break;
                    }
                    iVar8 = core_globals_get();
                    *(undefined1 *)(iVar8 + 0xda0) = 0;
                    iVar8 = core_globals_get();
                    *(byte *)(iVar8 + 0xb18) = *(byte *)(iVar8 + 0xb18) | 1;
                    uVar6 = nwk_get_extended_address();
                    uVar7 = nwk_get_short_address();
                    iVar8 = nwk_address_update(uVar6,uVar7,&uStack_36);
                    if (iVar8 == 0) {
                      nwk_address_lock_ref(uStack_36);
                      uStack_34 = 0;
                      uStack_32 = 0;
                      iVar8 = nwk_start_router(&uStack_34);
                      if (iVar8 == 0) {
                        zdo_dev_set_joined(1);
                        iVar8 = aps_secur_is_tc();
                        if (iVar8 != 0) {
                          iVar8 = core_globals_get();
                          *(ushort *)(iVar8 + 0x9bc) = *(ushort *)(iVar8 + 0x9bc) & 0xffe7 | 8;
                          iVar8 = core_globals_get();
                          uVar1 = *(ushort *)(iVar8 + 0xdb2);
                          iVar8 = core_globals_get();
                          *(ushort *)(iVar8 + 0x9bc) =
                               *(ushort *)(iVar8 + 0x9bc) & 0xfff9 |
                               (ushort)(((int)((uint)uVar1 << 0x1e) >> 0x1f & 3U ^ 1) << 1);
                        }
                        break;
                      }
                    }
_L0:
                    __assert_func(0,0,0,0);
_L0:
                    uVar9 = nwk_get_short_address();
                    if (0xfff7 < uVar9) break;
                  }
                }
              }
            }
          }
          iVar8 = core_globals_get();
          if (*(char *)(iVar8 + 0xda0) == '\x01') {
            return;
          }
        }
        else {
          iVar8 = core_globals_get();
          *(undefined1 *)(iVar8 + 0xda0) = 0;
        }
        bdb_comm_finish_step();
        _Var3 = bdb_comm_is_factory_new();
        iVar8 = core_globals_get();
        bdb_comm_put_app_signal
                  (0x101 - (short)CONCAT31(extraout_var,_Var3),*(bdb_comm_status_t *)(iVar8 + 0xda0)
                  );
      }
      else {
        bdb_comm_finish_step();
      }
      goto _L0;
    }
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar8 + 0xda0) = 1;
    iVar8 = zdo_dev_joined();
    if (iVar8 != 0) {
      uStack_1c = 0x1b4fffc;
      uStack_14 = 0;
      pcStack_18 = bdb_comm_permit_joining_req_cb;
      iVar8 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
      if (iVar8 != 0) {
        eStack_24.rsp = (ezb_zdp_nwk_mgmt_permit_joining_rsp_field_t *)0x0;
        eStack_24.error = -1;
        bdb_comm_permit_joining_req_cb(&eStack_24,(void *)0x0);
      }
      return;
    }
    iVar8 = core_globals_get();
    *(byte *)(iVar8 + 0xdb2) = *(byte *)(iVar8 + 0xdb2) | 1;
    iVar8 = core_globals_get();
    if (((*(byte *)(iVar8 + 0xdb2) & 1) != 0) &&
       (iVar8 = core_globals_get(), *(int *)(iVar8 + 0xda8) != 0)) goto _L0;
    iVar8 = core_globals_get();
    if (*(int *)(iVar8 + 0xdac) != 0) {
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xdb2) = *(byte *)(iVar8 + 0xdb2) & 0xfe;
_L0:
      iVar8 = core_globals_get();
      *(undefined1 *)(iVar8 + 0xda0) = 1;
      zdo_initiate_join();
      return;
    }
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar8 + 0xda0) = 3;
  } while( true );
}

