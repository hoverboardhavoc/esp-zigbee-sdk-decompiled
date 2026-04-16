/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_perform_next_step
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_perform_next_step(void)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  undefined3 extraout_var_00;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  byte bVar10;
  undefined2 uStack_36;
  undefined2 uStack_34;
  nwk_addr_ref_t ref;
  ezb_zdo_nwk_mgmt_permit_joining_req_result_t eStack_24;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
_L0:
  do {
    uVar3 = 6;
    while (iVar5 = core_globals_get(), *(char *)(iVar5 + 0xda3) != '\0') {
      iVar5 = core_globals_get();
      uVar6 = __ctzsi2(*(undefined1 *)(iVar5 + 0xda3));
      uVar3 = uVar6 & 0xff;
      if (uVar6 == 6) {
        return;
      }
      iVar5 = core_globals_get();
      if (((int)(uint)*(byte *)(iVar5 + 0xda3) >> (uVar6 & 0x1f) & 1U) == 0) goto _L0;
      if (uVar6 == 3) {
        iVar5 = core_globals_get();
        bVar10 = *(byte *)(iVar5 + 0xda1) >> 1;
_L147:
        if ((bVar10 & 1) != 0) goto _L0;
      }
      else if ((int)uVar6 < 4) {
        if (uVar6 == 1) {
_L0:
          iVar5 = core_globals_get();
          bVar10 = *(byte *)(iVar5 + 0xda1) >> 3;
          goto _L147;
        }
        if (uVar6 != 2) {
          uVar3 = 0;
          break;
        }
        iVar5 = core_globals_get();
        if ((*(byte *)(iVar5 + 0xda1) & 1) != 0) {
          uVar3 = 2;
          goto _L0;
        }
      }
      else {
        if (uVar6 == 4) {
          iVar5 = core_globals_get();
          bVar10 = *(byte *)(iVar5 + 0xda1) >> 2;
          goto _L147;
        }
        if (uVar6 == 5) goto _L0;
      }
_L0:
      iVar5 = core_globals_get();
      *(byte *)(iVar5 + 0xda3) = ~(byte)(1 << (uVar6 & 0x1f)) & *(byte *)(iVar5 + 0xda3);
    }
    if (uVar3 == 6) {
      return;
    }
_L0:
    iVar5 = core_globals_get();
    *(byte *)(iVar5 + 0xda3) = ~(byte)(1 << (uVar3 & 0x1f)) & *(byte *)(iVar5 + 0xda3);
    iVar5 = core_globals_get();
    *(char *)(iVar5 + 0xda2) = (char)uVar3;
    if (uVar3 != 3) {
      if (uVar3 < 4) {
        if (uVar3 == 1) {
          bdb_comm_touchlink_initiator();
          return;
        }
        if (uVar3 == 2) {
          iVar5 = core_globals_get();
          *(undefined1 *)(iVar5 + 0xda0) = 1;
          iVar5 = zdo_dev_joined();
          if (iVar5 != 0) {
            uStack_1c = 0x1b4fffc;
            uStack_14 = 0;
            pcStack_18 = bdb_comm_permit_joining_req_cb;
            iVar5 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
            if (iVar5 != 0) {
              eStack_24.rsp = (ezb_zdp_nwk_mgmt_permit_joining_rsp_field_t *)0x0;
              eStack_24.error = -1;
              bdb_comm_permit_joining_req_cb(&eStack_24,(void *)0x0);
            }
            return;
          }
          iVar5 = core_globals_get();
          *(byte *)(iVar5 + 0xdb2) = *(byte *)(iVar5 + 0xdb2) | 1;
          iVar5 = core_globals_get();
          if (((*(byte *)(iVar5 + 0xdb2) & 1) != 0) &&
             (iVar5 = core_globals_get(), *(int *)(iVar5 + 0xda8) != 0)) goto _L0;
          iVar5 = core_globals_get();
          if (*(int *)(iVar5 + 0xdac) != 0) {
            iVar5 = core_globals_get();
            *(byte *)(iVar5 + 0xdb2) = *(byte *)(iVar5 + 0xdb2) & 0xfe;
_L0:
            iVar5 = core_globals_get();
            *(undefined1 *)(iVar5 + 0xda0) = 1;
            zdo_initiate_join();
            return;
          }
          iVar5 = core_globals_get();
          *(undefined1 *)(iVar5 + 0xda0) = 3;
          bdb_comm_finish_step();
          iVar5 = core_globals_get();
          bdb_comm_put_app_signal(0x102,*(bdb_comm_status_t *)(iVar5 + 0xda0));
        }
        else {
          iVar5 = zdo_dev_joined();
          if (iVar5 == 0) {
            _Var4 = bdb_comm_is_factory_new();
            if (CONCAT31(extraout_var_00,_Var4) == 0) {
              iVar5 = core_globals_get();
              *(undefined1 *)(iVar5 + 0xda0) = 3;
              uVar3 = nwk_get_pan_channel();
              if (((uVar3 < 0x8000000) &&
                  (uVar3 = nwk_get_pan_channel(), 0x7ff < (uVar3 & 0x7ffffff))) &&
                 (iVar5 = nwk_get_panid(), iVar5 != 0xffff)) {
                piVar7 = (int *)nwk_get_extended_panid();
                if ((piVar7[1] + 1U != (uint)(*piVar7 == 0)) || (*piVar7 - 1U < 0xfffffffe)) {
                  piVar7 = (int *)nwk_get_extended_address();
                  if ((piVar7[1] + 1U != (uint)(*piVar7 == 0)) || (*piVar7 - 1U < 0xfffffffe)) {
                    iVar5 = nwk_get_short_address();
                    if (iVar5 != 0) goto _L0;
                    iVar5 = nwk_is_device_zc();
                    if (iVar5 != 0) {
                      while (iVar5 = nwk_is_authed(), iVar5 != 0) {
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
                        iVar5 = nwk_is_device_zc();
                        if ((iVar5 == 0) &&
                           ((iVar5 = nwk_is_device_zr(), iVar5 == 0 ||
                            (iVar5 = core_globals_get(), *(int *)(iVar5 + 0xdb0) << 0xc < 0)))) {
                          iVar5 = core_globals_get();
                          *(undefined1 *)(iVar5 + 0xda0) = 1;
                          zdo_initiate_rejoin();
                          break;
                        }
                        iVar5 = core_globals_get();
                        *(undefined1 *)(iVar5 + 0xda0) = 0;
                        iVar5 = core_globals_get();
                        *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) | 1;
                        uVar8 = nwk_get_extended_address();
                        uVar9 = nwk_get_short_address();
                        iVar5 = nwk_address_update(uVar8,uVar9,&uStack_36);
                        if (iVar5 == 0) {
                          nwk_address_lock_ref(uStack_36);
                          uStack_34 = 0;
                          ref._0_1_ = 0;
                          iVar5 = nwk_start_router(&uStack_34);
                          if (iVar5 == 0) {
                            zdo_dev_set_joined(1);
                            iVar5 = aps_secur_is_tc();
                            if (iVar5 != 0) {
                              iVar5 = core_globals_get();
                              *(ushort *)(iVar5 + 0x9bc) = *(ushort *)(iVar5 + 0x9bc) & 0xffe7 | 8;
                              iVar5 = core_globals_get();
                              uVar1 = *(ushort *)(iVar5 + 0xdb2);
                              iVar5 = core_globals_get();
                              *(ushort *)(iVar5 + 0x9bc) =
                                   *(ushort *)(iVar5 + 0x9bc) & 0xfff9 |
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
              iVar5 = core_globals_get();
              if (*(char *)(iVar5 + 0xda0) == '\x01') {
                return;
              }
            }
            else {
              iVar5 = core_globals_get();
              *(undefined1 *)(iVar5 + 0xda0) = 0;
            }
            bdb_comm_finish_step();
            _Var4 = bdb_comm_is_factory_new();
            iVar5 = core_globals_get();
            bdb_comm_put_app_signal
                      (0x101 - (short)CONCAT31(extraout_var,_Var4),
                       *(bdb_comm_status_t *)(iVar5 + 0xda0));
          }
          else {
            bdb_comm_finish_step();
          }
        }
      }
      else {
        if (uVar3 != 4) {
          if (uVar3 == 5) {
            bdb_comm_touchlink_target();
            return;
          }
          iVar5 = core_globals_get();
          log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar5 + 0xda2));
          goto _L0;
        }
        iVar5 = zdo_dev_joined();
        if (iVar5 == 0) {
          iVar5 = core_globals_get();
          *(undefined1 *)(iVar5 + 0xda0) = 3;
        }
        else {
          iVar5 = core_globals_get();
          *(undefined1 *)(iVar5 + 0xda0) = 9;
        }
        bdb_comm_finish_step();
        iVar5 = core_globals_get();
        bdb_comm_put_app_signal(0x104,*(bdb_comm_status_t *)(iVar5 + 0xda0));
      }
      goto _L0;
    }
    iVar5 = zdo_dev_joined();
    cVar2 = '\f';
    if (iVar5 == 0) {
      iVar5 = nwk_is_device_zczr();
      cVar2 = '\t';
      if (iVar5 != 0) {
        iVar5 = core_globals_get();
        cVar2 = '\x01';
        *(byte *)(iVar5 + 0xdb2) = *(byte *)(iVar5 + 0xdb2) | 1;
      }
    }
    iVar5 = core_globals_get();
    *(char *)(iVar5 + 0xda0) = cVar2;
    if (cVar2 == '\x01') {
      iVar5 = core_globals_get();
      if (((*(byte *)(iVar5 + 0xdb2) & 1) != 0) &&
         (iVar5 = core_globals_get(), *(int *)(iVar5 + 0xda8) != 0)) {
_L0:
        iVar5 = core_globals_get();
        *(undefined1 *)(iVar5 + 0xda0) = 1;
        zdo_initiate_formation();
        return;
      }
      iVar5 = core_globals_get();
      if (*(int *)(iVar5 + 0xdac) != 0) {
        iVar5 = core_globals_get();
        *(byte *)(iVar5 + 0xdb2) = *(byte *)(iVar5 + 0xdb2) & 0xfe;
        goto _L0;
      }
      iVar5 = core_globals_get();
      *(undefined1 *)(iVar5 + 0xda0) = 5;
    }
    bdb_comm_finish_step();
    iVar5 = core_globals_get();
    bdb_comm_put_app_signal(0x103,*(bdb_comm_status_t *)(iVar5 + 0xda0));
  } while( true );
}

