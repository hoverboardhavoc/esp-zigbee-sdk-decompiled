/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_network_formation_perform_form
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_formation_perform_form(void)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  byte bVar10;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined1 uStack_32;
  ezb_zdo_nwk_mgmt_permit_joining_req_result_t eStack_24;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
code_r0x00010ed4:
  iVar9 = core_globals_get();
  if (((*(byte *)(iVar9 + 0xdb2) & 1) == 0) ||
     (iVar9 = core_globals_get(), *(int *)(iVar9 + 0xda8) == 0)) {
    iVar9 = core_globals_get();
    if (*(int *)(iVar9 + 0xdac) == 0) {
      iVar9 = core_globals_get();
      *(undefined1 *)(iVar9 + 0xda0) = 5;
bdb_comm_finish_network_formation:
      bdb_comm_finish_step();
      iVar9 = core_globals_get();
      bdb_comm_put_app_signal(0x103,*(bdb_comm_status_t *)(iVar9 + 0xda0));
_L0:
      do {
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
            bVar10 = *(byte *)(iVar9 + 0xda1) >> 1;
_L147:
            if ((bVar10 & 1) != 0) goto _L0;
          }
          else if ((int)uVar5 < 4) {
            if (uVar5 == 1) {
_L0:
              iVar9 = core_globals_get();
              bVar10 = *(byte *)(iVar9 + 0xda1) >> 3;
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
              bVar10 = *(byte *)(iVar9 + 0xda1) >> 2;
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
        if (uVar3 == 3) goto _L0;
        if (uVar3 < 4) {
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
                if (((uVar3 < 0x8000000) &&
                    (uVar3 = nwk_get_pan_channel(), 0x7ff < (uVar3 & 0x7ffffff))) &&
                   (iVar9 = nwk_get_panid(), iVar9 != 0xffff)) {
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
                                *(ushort *)(iVar9 + 0x9bc) = *(ushort *)(iVar9 + 0x9bc) & 0xffe7 | 8
                                ;
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
                if (*(char *)(iVar9 + 0xda0) == '\x01') {
                  return;
                }
              }
              else {
                iVar9 = core_globals_get();
                *(undefined1 *)(iVar9 + 0xda0) = 0;
              }
              bdb_comm_finish_step();
              _Var4 = bdb_comm_is_factory_new();
              iVar9 = core_globals_get();
              bdb_comm_put_app_signal
                        (0x101 - (short)CONCAT31(extraout_var,_Var4),
                         *(bdb_comm_status_t *)(iVar9 + 0xda0));
            }
            else {
              bdb_comm_finish_step();
            }
            goto _L0;
          }
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 1;
          iVar9 = zdo_dev_joined();
          if (iVar9 != 0) {
            uStack_1c = 0x1b4fffc;
            uStack_14 = 0;
            pcStack_18 = bdb_comm_permit_joining_req_cb;
            iVar9 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
            if (iVar9 != 0) {
              eStack_24.rsp = (ezb_zdp_nwk_mgmt_permit_joining_rsp_field_t *)0x0;
              eStack_24.error = -1;
              bdb_comm_permit_joining_req_cb(&eStack_24,(void *)0x0);
            }
            return;
          }
          iVar9 = core_globals_get();
          *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) | 1;
          iVar9 = core_globals_get();
          if (((*(byte *)(iVar9 + 0xdb2) & 1) == 0) ||
             (iVar9 = core_globals_get(), *(int *)(iVar9 + 0xda8) == 0)) {
            iVar9 = core_globals_get();
            if (*(int *)(iVar9 + 0xdac) == 0) {
              iVar9 = core_globals_get();
              *(undefined1 *)(iVar9 + 0xda0) = 3;
              bdb_comm_finish_step();
              iVar9 = core_globals_get();
              bdb_comm_put_app_signal(0x102,*(bdb_comm_status_t *)(iVar9 + 0xda0));
              goto _L0;
            }
            iVar9 = core_globals_get();
            *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
          }
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xda0) = 1;
          zdo_initiate_join();
          return;
        }
        if (uVar3 != 4) {
          if (uVar3 != 5) {
            iVar9 = core_globals_get();
            log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar9 + 0xda2));
            goto _L0;
          }
          bdb_comm_touchlink_target();
          return;
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
      } while( true );
    }
    iVar9 = core_globals_get();
    *(byte *)(iVar9 + 0xdb2) = *(byte *)(iVar9 + 0xdb2) & 0xfe;
  }
  iVar9 = core_globals_get();
  *(undefined1 *)(iVar9 + 0xda0) = 1;
  zdo_initiate_formation();
  return;
_L0:
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
  *(char *)(iVar9 + 0xda0) = cVar2;
  if (cVar2 == '\x01') goto code_r0x00010ed4;
  goto bdb_comm_finish_network_formation;
}

