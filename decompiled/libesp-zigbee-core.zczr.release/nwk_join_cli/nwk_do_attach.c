/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_do_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_do_attach(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined2 *__src;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  undefined2 *puVar14;
  byte bVar15;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined4 uStack_50;
  undefined2 uStack_46;
  byte bStack_44;
  byte bStack_43;
  undefined1 uStack_42;
  
  uVar4 = nwk_address_get_panid_ref();
  if (uVar4 == 0xff) {
    return 0x2c3;
  }
  iVar5 = nwk_is_device_zed();
  cVar1 = *(char *)(param_1 + 8);
  iVar6 = core_globals_get();
  uVar12 = 0;
  __src = (undefined2 *)0x0;
  do {
    uVar12 = bitmap_find_next_bit(iVar6 + 0xba4,6,uVar12);
    uVar12 = uVar12 & 0xff;
    if (5 < uVar12) {
      if (__src == (undefined2 *)0x0) {
        return 0x2c3;
      }
      nwk_address_get_panid(uVar4,&uStack_54);
      nwk_set_panid(uStack_54);
      iVar7 = core_globals_get();
      *(undefined2 **)(iVar7 + 0xac4) = __src;
      if (*(char *)(param_1 + 8) == '\0') {
        uVar12 = 3;
        if (*(int *)(__src + 8) << 0x13 < 0) goto _L0;
_L0:
        uVar12 = 0;
_L0:
        iVar7 = core_globals_get();
        *(char *)(iVar7 + 0xad3) = (char)uVar12;
        if (uVar12 == 3) {
          uVar2 = *(undefined1 *)(param_1 + 9);
          bVar15 = 0;
          uVar10 = 0;
          goto _L0;
        }
        if (uVar12 < 4) {
          if (uVar12 == 0) {
            uStack_50 = CONCAT31(uStack_50._1_3_,((*(uint *)(__src + 8) & 0x20000000) == 0) + '\x02'
                                );
            memcpy((void *)((int)&uStack_50 + 2),__src,8);
            uStack_46 = uStack_54;
            bStack_44 = (byte)(*(uint *)(__src + 8) >> 7) & 0x1f;
            bStack_43 = (byte)*(undefined4 *)(__src + 8) & 0x7f;
            uStack_42 = *(undefined1 *)(param_1 + 9);
            iVar5 = nwk_mm_asso_request(*(byte *)((int)__src + 0x13) & 0x1f,&uStack_50);
            if (iVar5 != 0) {
              return iVar5;
            }
          }
          else {
            uVar2 = *(undefined1 *)(param_1 + 9);
            bVar15 = *(byte *)(param_1 + 10) & 1;
            iVar5 = zmsg_alloc((-bVar15 & 0xe) + 0x21);
            if (iVar5 == 0) {
              return 1;
            }
            zmsg_set_offset(0);
            uVar10 = nwk_get_short_address();
            nwk_frame_write_hdr(iVar5,uVar10,*__src,1,bVar15,0);
            iVar6 = core_globals_get();
            cVar1 = *(char *)(iVar6 + 0x9d9);
            *(char *)(iVar6 + 0x9d9) = cVar1 + '\x01';
            uStack_50 = CONCAT31(uStack_50._1_3_,cVar1);
            zmsg_write_bytes(iVar5,7,1,&uStack_50);
            zmsg_append_u8_isra_0(iVar5,6);
            zmsg_append_u8_isra_0(iVar5,uVar2);
            nwk_fwd_mac_data_req(iVar5,*(byte *)((int)__src + 0x13) & 0x1f,*__src,0);
          }
          return 0;
        }
        uVar12 = uVar12 - 4 & 0xff;
        uVar10 = 1;
        if (uVar12 < 2) {
          uVar2 = *(undefined1 *)(param_1 + 9);
          bVar15 = *(byte *)(param_1 + 10) & 1;
_L0:
          iVar5 = nwk_send_network_comm_req(__src,uVar10,bVar15,uVar2);
          return iVar5;
        }
      }
      else if (*(char *)(param_1 + 8) == '\x02') {
        uStack_50 = 0x5040201;
        uVar12 = (uint)*(byte *)((int)&uStack_50 +
                                (*(byte *)(param_1 + 10) & 1) + (*(uint *)(__src + 8) >> 0xb & 2));
        if (uVar12 == 0) goto _L0;
_L0:
        uVar9 = nwk_get_short_address();
        if ((0xfff7 < uVar9) || (iVar7 = nwk_get_short_address(), iVar7 == 0)) {
          nwk_assign_shortaddr();
          nwk_set_short_address();
        }
        uVar10 = nwk_get_extended_address();
        uVar11 = nwk_get_short_address();
        uStack_52 = 0;
        iVar7 = nwk_address_update(uVar10,uVar11,&uStack_52);
        if (iVar7 == 0) {
          uStack_50 = 1 << (*(uint *)(__src + 8) & 0x1f) & 0x7ffffffU |
                      (*(uint *)(__src + 8) >> 7) << 0x1b;
          iVar7 = nwk_mm_set_pib_attr(*(byte *)((int)__src + 0x13) & 0x1f,0x61,&uStack_50);
          if (iVar7 == 0) {
            nwk_mm_set_pib_attr(*(byte *)((int)__src + 0x13) & 0x1f,0x4b,__src);
            goto _L0;
          }
        }
      }
      __assert_func(0,0,0,0);
    }
    iVar7 = uVar12 * 0x14;
    puVar3 = __src;
    if (((*(byte *)(iVar6 + iVar7 + 0xb34) == uVar4) &&
        (bVar15 = *(byte *)(iVar6 + iVar7 + 0xb35), iVar8 = core_globals_get(),
        *(byte *)(iVar8 + 0xa37) <= bVar15)) &&
       (iVar8 = *(int *)(iVar6 + iVar7 + 0xb3c), iVar8 << 2 < 0)) {
      if (cVar1 == '\0') {
        if (iVar8 << 1 < 0) {
          iVar13 = iVar8 << 0x10;
          if (iVar5 == 0) {
            iVar13 = iVar8 << 0x11;
          }
          if (iVar13 < 0) goto _L0;
        }
      }
      else {
_L0:
        puVar14 = (undefined2 *)(iVar7 + 0xb2c + iVar6);
        puVar3 = puVar14;
        if (__src != (undefined2 *)0x0) {
          if (((uint)*(byte *)(puVar14 + 5) != (uint)*(byte *)(__src + 5)) &&
             (puVar3 = __src,
             (int)(((uint)*(byte *)(__src + 5) - (uint)*(byte *)(puVar14 + 5)) * 0x1000000) >> 0x18
             < 0)) {
            puVar3 = puVar14;
          }
        }
      }
    }
    __src = puVar3;
    uVar12 = uVar12 + 1 & 0xff;
  } while( true );
}

