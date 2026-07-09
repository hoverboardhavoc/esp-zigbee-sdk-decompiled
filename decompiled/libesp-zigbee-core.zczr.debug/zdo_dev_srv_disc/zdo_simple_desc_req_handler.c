/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_simple_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_simple_desc_req_handler(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  void *__src;
  uint uVar4;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_14 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if (param_1 == 0) {
    iVar2 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    iVar2 = 0xfe;
  }
  else {
    iVar2 = zdo_op_simple_desc_req(&uStack_14,0);
    if (iVar2 == 0) {
      uVar4 = uStack_14 & 0xffff;
      if (uVar4 < 0xfff8) {
        uStack_2c = CONCAT22((undefined2)uStack_14,(undefined2)uStack_2c);
        uVar3 = nwk_get_short_address();
        if (uVar4 == uVar3) {
          if (((uStack_14 >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
            __src = (void *)af_get_simple_desc();
            cVar1 = '\0';
            if (__src == (void *)0x0) {
              cVar1 = -0x7d;
            }
            uStack_2c._0_1_ = cVar1;
            if (cVar1 == '\0') {
              memcpy(&uStack_24,__src,0x10);
            }
          }
          else {
            uStack_2c._0_1_ = -0x7e;
          }
        }
        else {
          uStack_2c._0_1_ = -0x80;
          iVar2 = nwk_is_device_zczr();
          if (iVar2 != 0) {
            uStack_2c._0_1_ = -0x7f;
            iVar2 = 0;
            do {
              iVar2 = nwk_child_table_next(iVar2);
              if (iVar2 == 0) goto _L0;
            } while (((*(uint *)(iVar2 + 0xc) & 0x3c0) != 0x40) ||
                    (uVar3 = uStack_14 & 0xffff, uVar4 = nwk_neighbor_get_shortaddr(iVar2),
                    uVar3 != uVar4));
            uStack_2c._0_1_ = -0x77;
          }
        }
_L0:
        iVar2 = zdo_op_simple_desc_rsp(*(undefined4 *)(param_2 + 0x14),&uStack_2c,1);
        if (iVar2 != 0) {
          iVar2 = 0xfe;
        }
      }
      else {
        iVar2 = 0xfe;
      }
    }
    else {
      iVar2 = 0xfe;
    }
  }
  return iVar2;
}

